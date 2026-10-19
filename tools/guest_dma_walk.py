# Walk a source-chain DMA list in a running reo_recomp's guest RAM (read-only).
#   python -I tools/guest_dma_walk.py <pid> <elf> <tag_addr_hex> [max_tags]
import runpy, struct, sys
pid, elf, addr = sys.argv[1], sys.argv[2], int(sys.argv[3], 16); limit = int(sys.argv[4]) if len(sys.argv) > 4 else 64
sys.argv = [sys.argv[0], pid, elf]              # reuse guest_peek's locator
g = runpy.run_path(__file__.replace('guest_dma_walk.py', 'guest_peek.py'), run_name='peek')
h, base, read = g['h'], g['base'], g['read']
VIF = {0:'NOP',1:'STCYCL',2:'OFFSET',3:'BASE',4:'ITOP',5:'STMOD',6:'MSKPATH3',7:'MARK',0x10:'FLUSHE',0x11:'FLUSH',0x13:'FLUSHA',0x14:'MSCAL',0x15:'MSCALF',0x17:'MSCNT',0x20:'STMASK',0x30:'STROW',0x31:'STCOL',0x4a:'MPG',0x50:'DIRECT',0x51:'DIRECTHL'}
ID = ['refe','cnt','next','ref','refs','call','ret','end']
stack = []
for n in range(limit):
    lo, hi = struct.unpack('<QQ', read(h, base + (addr & 0x1ffffff0), 16))
    qwc, tid, irq, nxt = lo & 0xffff, (lo >> 28) & 7, (lo >> 31) & 1, (lo >> 32) & 0x7ffffff0
    v = [(hi >> s) & 0xffffffff for s in (0, 32)]
    vs = ' '.join('%s%s(%x)' % ('I:' if c >> 31 else '', VIF.get((c >> 24) & 0x7f, hex((c >> 24) & 0x7f)), c & 0xffff) for c in v)
    print('%3d @%08x %-4s qwc=%-4d irq=%d addr=%08x  vif: %s' % (n, addr, ID[tid], qwc, irq, nxt, vs))
    if tid == 7 or irq: print('  chain ends (end tag or IRQ)'); break
    if tid == 0: print('  refe: ends'); break
    if tid == 1: addr = addr + 16 + qwc * 16
    elif tid == 2: addr = nxt
    elif tid in (3, 4): addr = addr + 16
    elif tid == 5: stack.append(addr + 16 + qwc * 16); addr = nxt
    elif tid == 6:
        if not stack: print('  ret with empty stack: ends'); break
        addr = stack.pop()
