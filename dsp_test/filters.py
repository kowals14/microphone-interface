from ctypes import CDLL
from ctypes import POINTER
from ctypes import c_int
from ctypes import c_double
from ctypes import c_void_p
from ctypes import Structure

class user_params(Structure):
    _fields_ = [
     ("type", c_int),
     ("Fs", c_double),
     ("f0", c_double),
     ("dbGain", c_double),
     ("BW", c_double),
    ]

_filter = CDLL('./libfilters.so')

lowpass = _filter.lowpass
lowpass.argtypes = [POINTER(c_double), POINTER(c_double), user_params]
lowpass.restype = c_double

filter = _filter.filter
filter.argtypes = [POINTER(c_double), POINTER(c_double), c_int, user_params]
filter.restype = c_void_p

get_params = _filter.get_params
get_params.argtypes = [c_int, c_double, c_double, c_double, c_double]
get_params.restype = user_params