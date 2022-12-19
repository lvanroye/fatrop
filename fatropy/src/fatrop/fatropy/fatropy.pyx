from fatropy cimport OCPBuilder
from fatropy cimport FatropAlg
from fatropy cimport FatropApplication
from fatropy cimport OCPSolutionSampler
from libcpp.memory cimport shared_ptr 
from libcpp.vector cimport vector
import json
import numpy as np

cdef class OCP:
    cdef OCPBuilder *myOCPBuilder  # Hold a C++ instance which we are wrapping
    cdef public dict OCPspecs # Public dict attribute to contain specs as defined in json file
    cdef shared_ptr[FatropApplication] myFatropApplication
    
    def __cinit__(self, functions, specfile):
        self.myOCPBuilder = new OCPBuilder(functions.encode('utf-8'),specfile.encode('utf-8'))
        specfile_object = open(specfile.encode('utf-8'),"r")
        self.OCPspecs = json.load(specfile_object)
        specfile_object.close()
        self.myFatropApplication = self.myOCPBuilder.Build()

    def Optimize(self):
        return self.myFatropApplication.get().Optimize()
    def WarmStart(self):
        return self.myFatropApplication.get().WarmStart()
    def Sample(self, name):
        # allocate sampler
        cdef OCPSolutionSampler * sampler = new OCPSolutionSampler(self.myOCPBuilder.GetSamplerCustom(name.encode('utf-8')))
        # allocate buffer
        cdef vector[double] buffer = vector[double](sampler.Size())
        # use sampler
        sampler.Sample(buffer)
        n_rows = sampler.n_rows()
        n_cols = sampler.n_cols()
        K = sampler.K()
        # deallocate sampler
        del sampler
        if n_cols == 1:
            return np.asarray(buffer).reshape((K, n_rows))
        else:
            return np.asarray(buffer).reshape((K, n_rows, n_cols))


    # @property
    # def sd_time(self):
    #     return self.myOCPBuilder.fatropalg.get().sd_time

    # @property
    # def hess_time(self):
    #     return self.myOCPBuilder.fatropalg.get().hess_time

    # @property
    # def jac_time(self):
    #     return self.myOCPBuilder.fatropalg.get().jac_time

    # @property
    # def cv_time(self):
    #     return self.myOCPBuilder.fatropalg.get().cv_time

    # @property
    # def grad_time(self):
    #     return self.myOCPBuilder.fatropalg.get().grad_time

    # @property
    # def obj_time(self):
    #     return self.myOCPBuilder.fatropalg.get().obj_time

    # @property
    # def init_time(self):
    #     return self.myOCPBuilder.fatropalg.get().init_time

    # @property
    # def total_time(self):
    #     return self.myOCPBuilder.fatropalg.get().total_time

    def SetBounds(self):
        self.myOCPBuilder.SetBounds()

    # def SetInitial(self):
    #     self.myOCPBuilder.SetInitial()
    def SetParams(self, stage_params_in, global_params_in):
        self.myOCPBuilder.ocptempladapter.get().SetParams(stage_params_in, global_params_in)
    def SetInitial(self, initial_u, initial_x):
        self.myOCPBuilder.ocptempladapter.get().SetInitial(self.myOCPBuilder.fatropdata, initial_u, initial_x)

    # Attribute access
    @property
    def initial_u(self):
        return self.myOCPBuilder.initial_u
    @initial_u.setter
    def initial_u(self, initial_u):
        self.myOCPBuilder.initial_u = initial_u

    # Attribute access
    @property
    def initial_x(self):
        return self.myOCPBuilder.initial_x
    @initial_x.setter
    def initial_x(self, initial_x):
        self.myOCPBuilder.initial_x = initial_x
    
    # Attribute access
    @property
    def lower(self):
        return self.myOCPBuilder.lower
    @lower.setter
    def lower(self, lower):
        self.myOCPBuilder.lower = lower

    # Attribute access
    @property
    def upper(self):
        return self.myOCPBuilder.upper
    @upper.setter
    def upper(self, upper):
        self.myOCPBuilder.upper = upper

    # Attribute access
    @property
    def lowerF(self):
        return self.myOCPBuilder.lowerF
    @lowerF.setter
    def lowerF(self, lowerF):
        self.myOCPBuilder.lowerF = lowerF

    # Attribute access
    @property
    def upperF(self):
        return self.myOCPBuilder.upperF
    @upperF.setter
    def upperF(self, upperF):
        self.myOCPBuilder.upperF = upperF

    # Attribute access
    @property
    def x_curr(self):
        nels = self.myOCPBuilder.fatropdata.get().x_curr.nels()
        retval = np.empty(nels)
        for ii in range(nels):
           retval[ii] = self.myOCPBuilder.fatropdata.get().x_curr.get_el(ii)
        return retval
    
    # Attribute access
    @property
    def x_next(self):
        nels = self.myOCPBuilder.fatropdata.get().x_next.nels()
        retval = np.empty(nels)
        for ii in range(nels):
           retval[ii] = self.myOCPBuilder.fatropdata.get().x_next.get_el(ii)
        return retval

    # Attribute access
    @property
    # TODO make this more efficient
    def u0_sol(self):
        nu = self.OCPspecs["nu"]
        retval = np.empty(nu)
        for ii in range(nu):
           retval[ii] = self.myOCPBuilder.fatropdata.get().x_curr.get_el(ii)
        return retval

    # Attribute access
    @property
    # TODO make this more efficient
    def u_sol(self):
        nu = self.OCPspecs["nu"]
        nx_plus_nu = self.OCPspecs["nx"]+nu
        K = self.OCPspecs["K"]
        retval = np.empty((nu,K-1))
        for ii in range(K-1):
            for jj in range(nu):               
                retval[jj,ii] = self.myOCPBuilder.fatropdata.get().x_curr.get_el(jj+ii*(nx_plus_nu))
        return retval

    @property
    # TODO make this more efficient
    def x_sol(self):
        nx = self.OCPspecs["nx"]
        nu = self.OCPspecs["nu"]
        nx_plus_nu = nx+nu
        K = self.OCPspecs["K"]
        retval = np.ones((nx,K))
        for ii in range(K-1):
            for jj in range(nx):               
                retval[jj,ii] = self.myOCPBuilder.fatropdata.get().x_curr.get_el(nu+jj+ii*(nx_plus_nu))
        for jj in range(nx):
            retval[jj,K-1] = self.myOCPBuilder.fatropdata.get().x_curr.get_el(jj+(K-1)*(nx_plus_nu))
        return retval

    # Attribute access
    @property
    def n_eqs(self):
        return self.myOCPBuilder.fatropdata.get().n_eqs

    # Attribute access
    @property
    def n_ineqs(self):
        return self.myOCPBuilder.fatropdata.get().n_ineqs

    def __dealloc__(self):
        del self.myOCPBuilder
