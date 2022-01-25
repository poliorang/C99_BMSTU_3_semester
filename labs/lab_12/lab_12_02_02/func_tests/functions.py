import ctypes

lib = ctypes.CDLL("../libapp.dll")

_fill_fibonacci = lib.fill_fibonacci
_fill_fibonacci.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fill_fibonacci.restype = None

_filter = lib.filter
_filter.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int),
                                          ctypes.POINTER(ctypes.c_int))
_filter.restype = ctypes.c_int


def fill_fibonacci(n):
    array = (ctypes.c_int * n)()
    _fill_fibonacci(array, n)

    return list(array)


def filter_without_stock_memory(nums):
    src_len = len(nums)
    src = (ctypes.c_int * src_len)(*nums)
    dst_len = ctypes.c_int(0)

    rc = _filter(src, src_len, None, dst_len)
    if rc:
        dst = (ctypes.c_int * dst_len.value)()
        _filter(src, src_len, dst, dst_len)

        return list(dst)
    else:
        return list()


def filter_with_stock_memory(nums):
    src_len = len(nums)
    dst_len = ctypes.c_int(len(nums))
    src = (ctypes.c_int * src_len)(*nums)
    dst = (ctypes.c_int * dst_len.value)()
    _filter(src, src_len, dst, dst_len)

    return list(dst)
