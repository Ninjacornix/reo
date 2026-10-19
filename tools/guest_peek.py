# Read guest (PS2 EE) RAM words from a running reo_recomp process, read-only.
# Locates the 32 MiB RDRAM heap block by matching the ELF's first loaded segment.
#   python -I tools/guest_peek.py <pid> <elf> <guest_addr_hex>[:count] ...
import ctypes as c, ctypes.wintypes as w, struct, sys

k = c.WinDLL('kernel32', use_last_error=True)
class MBI(c.Structure):
    _fields_ = [('BaseAddress', c.c_void_p), ('AllocationBase', c.c_void_p), ('AllocationProtect', w.DWORD),
                ('PartitionId', w.WORD), ('RegionSize', c.c_size_t), ('State', w.DWORD), ('Protect', w.DWORD), ('Type', w.DWORD)]
k.VirtualQueryEx.argtypes = [w.HANDLE, c.c_void_p, c.POINTER(MBI), c.c_size_t]
k.VirtualQueryEx.restype = c.c_size_t
k.ReadProcessMemory.argtypes = [w.HANDLE, c.c_void_p, c.c_void_p, c.c_size_t, c.POINTER(c.c_size_t)]
k.OpenProcess.restype = w.HANDLE

def read(h, addr, n):
    buf = (c.c_char * n)(); got = c.c_size_t()
    if not k.ReadProcessMemory(h, c.c_void_p(addr), buf, n, c.byref(got)) or got.value != n: return None
    return buf.raw

pid = int(sys.argv[1]); elf = open(sys.argv[2], 'rb').read()
phoff, = struct.unpack_from('<I', elf, 0x1c); phnum, = struct.unpack_from('<H', elf, 0x2c)
seg = None
for i in range(phnum):
    t, off, vaddr, _, filesz = struct.unpack_from('<IIIII', elf, phoff + 32 * i)
    if t == 1 and filesz >= 64: seg = (vaddr, elf[off:off + 64]); break
h = k.OpenProcess(0x0410, False, pid)   # QUERY_INFORMATION | VM_READ
if not h: sys.exit('OpenProcess failed')
addr, base = 0, None
while base is None:
    m = MBI()
    if not k.VirtualQueryEx(h, c.c_void_p(addr), c.byref(m), c.sizeof(m)): break
    if m.State == 0x1000 and m.RegionSize >= 0x2000000:
        lo = m.BaseAddress or 0
        for slack in (0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x1000):
            b = read(h, lo + slack + seg[0], 64)
            if b == seg[1]: base = lo + slack; break
    addr = (m.BaseAddress or 0) + m.RegionSize
if base is None: sys.exit('RDRAM not found')
print('rdram host base 0x%x' % base)
for spec in sys.argv[3:]:
    a, _, n = spec.partition(':'); a = int(a, 16); n = int(n or '1')
    data = read(h, base + a, 4 * n)
    print('0x%08x:' % a, ' '.join('%08x' % v for v in struct.unpack('<%dI' % n, data)))
