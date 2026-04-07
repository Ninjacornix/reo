#!/usr/bin/env python3
"""Dump TEX chunk structure from NBD files in NETBIO00.DAT
Uses RE Outbreak's custom 16-bit word LZ77 decompression (not standard LZSS)"""
import struct, sys, os

def parse_afs(f, base=0):
    f.seek(base)
    sig = f.read(4)
    if sig[:3] != b'AFS':
        return []
    count = struct.unpack('<I', f.read(4))[0]
    if count > 65536:
        return []
    entries = []
    for i in range(count):
        off, sz = struct.unpack('<II', f.read(8))
        entries.append([off, sz, f"file_{i:04d}"])
    ft_off, ft_sz = struct.unpack('<II', f.read(8))
    if ft_off > 0 and ft_sz >= count * 48:
        for i in range(count):
            f.seek(base + ft_off + i * 48)
            name = f.read(32).split(b'\x00')[0].decode('ascii', errors='replace').strip()
            if name:
                entries[i][2] = name
    for e in entries:
        e[0] += base
    return entries

def parse_nbd_chunks(data):
    chunks = []
    pos = 0
    while pos + 16 <= len(data):
        typ, off, sz, cnt = struct.unpack_from('<IIII', data, pos)
        if typ == 0 and off == 0:
            break
        type_bytes = struct.pack('<I', typ)
        type_str = type_bytes.decode('ascii', errors='replace').rstrip('\x00')
        chunks.append({'type': type_str, 'type_raw': typ, 'offset': off, 'size': sz, 'count': cnt})
        pos += 16
    return chunks

def ob_decompress(src):
    """RE Outbreak 16-bit word LZ77 decompression.
    Based on OBSld::decompress() from libthanatos/REOF2."""
    if len(src) < 2:
        return b''

    # Work in 16-bit words
    word_count = len(src) // 2
    words = struct.unpack_from(f'<{word_count}H', src)

    output = []
    pos = 0

    while pos < len(words):
        # Read 16-bit control word
        ctrl = words[pos]; pos += 1

        for bit in range(15, -1, -1):  # MSB first
            if pos >= len(words):
                break

            if ctrl & (1 << bit):
                # Compressed token
                if pos >= len(words):
                    break
                mode = words[pos]; pos += 1
                count = mode >> 11       # top 5 bits
                offset = mode & 0x7FF    # bottom 11 bits

                if count == 0 and offset == 0:
                    # Termination sentinel
                    return struct.pack(f'<{len(output)}H', *output)

                if count == 0:
                    # Extended count from next word
                    if pos >= len(words):
                        break
                    count = words[pos]; pos += 1

                if offset == 0:
                    # Zero-fill RLE
                    output.extend([0] * count)
                else:
                    # Back reference
                    src_pos = len(output) - offset
                    for j in range(count):
                        if src_pos + j >= 0 and src_pos + j < len(output):
                            output.append(output[src_pos + j])
                        else:
                            output.append(0)
            else:
                # Literal 16-bit word
                output.append(words[pos]); pos += 1

    return struct.pack(f'<{len(output)}H', *output)

def dump_hex(data, offset=0, max_bytes=128, indent="  "):
    for row in range(0, min(len(data), max_bytes), 16):
        hexpart = ' '.join(f'{data[row+i]:02X}' if row+i < len(data) else '  ' for i in range(16))
        ascpart = ''.join(chr(data[row+i]) if 32 <= data[row+i] < 127 else '.' for i in range(16) if row+i < len(data))
        print(f"{indent}{offset+row:06X}: {hexpart}  {ascpart}")

def parse_tim2_info(data, offset=0):
    if offset + 16 > len(data):
        return None
    if data[offset:offset+4] != b'TIM2':
        return None
    ver = data[offset+4]
    align = data[offset+5]
    tex_count = struct.unpack_from('<H', data, offset+6)[0]
    # RE Outbreak extension: globalTextureId at offset 8
    global_tex_id = struct.unpack_from('<H', data, offset+8)[0]

    info = {'version': ver, 'alignment': align, 'tex_count': tex_count,
            'global_tex_id': global_tex_id, 'textures': []}

    hdr_size = 0x80 if align else 16
    tex_off = offset + hdr_size

    for i in range(tex_count):
        if tex_off + 48 > len(data):
            break
        th = data[tex_off:]
        total_sz = struct.unpack_from('<I', th, 0)[0]
        pal_sz = struct.unpack_from('<I', th, 4)[0]
        img_sz = struct.unpack_from('<I', th, 8)[0]
        hdr_sz = struct.unpack_from('<H', th, 12)[0]
        colors = struct.unpack_from('<H', th, 14)[0]
        # imageFormat at 16, mipmapLevels at 17
        # clutType at 18, imageType at 19
        img_format = th[16]
        mipmaps = th[17]
        clut_type = th[18]
        img_type = th[19]  # 1=RGB16, 2=RGB24, 3=RGBA32, 4=IDX4, 5=IDX8
        w = struct.unpack_from('<H', th, 20)[0]
        h = struct.unpack_from('<H', th, 22)[0]
        gs_tex0 = struct.unpack_from('<Q', th, 24)[0] if tex_off + 32 <= len(data) else 0
        gs_tex1 = struct.unpack_from('<Q', th, 32)[0] if tex_off + 40 <= len(data) else 0

        img_type_names = {1:'RGB16', 2:'RGB24', 3:'RGBA32', 4:'IDX4', 5:'IDX8'}
        tex_info = {
            'total_size': total_sz, 'palette_size': pal_sz, 'image_size': img_sz,
            'header_size': hdr_sz, 'colors': colors,
            'img_format': img_format, 'mipmaps': mipmaps, 'clut_type': clut_type,
            'img_type': img_type, 'img_type_name': img_type_names.get(img_type, f'UNK{img_type}'),
            'width': w, 'height': h,
            'gs_tex0': gs_tex0, 'gs_tex1': gs_tex1,
        }
        info['textures'].append(tex_info)
        tex_off += total_sz

    return info

def analyze_tex_chunk(data, count):
    print(f"  TEX chunk: {len(data)} bytes, count={count}")

    # Format: [compressed_size:4][compressed_data:compressed_size] × count
    pos = 0
    for i in range(count):
        if pos + 4 > len(data):
            print(f"  Texture [{i}]: out of bounds at offset 0x{pos:X}")
            break

        comp_size = struct.unpack_from('<I', data, pos)[0]
        print(f"\n  Texture [{i}]: offset=0x{pos:X}, compressed_size={comp_size} (0x{comp_size:X})")

        if pos + 4 + comp_size > len(data):
            print(f"    WARNING: compressed data extends beyond chunk (need {comp_size}, have {len(data) - pos - 4})")
            comp_size = len(data) - pos - 4

        comp_data = data[pos + 4 : pos + 4 + comp_size]

        # Show first few bytes of compressed data
        print(f"    Compressed data (first 32 bytes):")
        dump_hex(comp_data, max_bytes=32, indent="      ")

        # Decompress with OB LZ77
        try:
            dec = ob_decompress(comp_data)
            print(f"    Decompressed: {len(dec)} bytes")

            # Check for TIM2
            tim2 = parse_tim2_info(dec)
            if tim2:
                print(f"    ** Valid TIM2! v{tim2['version']}, {tim2['tex_count']} image(s), globalTexId={tim2['global_tex_id']}")
                for j, t in enumerate(tim2['textures']):
                    print(f"       Image[{j}]: {t['width']}x{t['height']} type={t['img_type_name']} clut_type=0x{t['clut_type']:02X} colors={t['colors']}")
                    print(f"                total={t['total_size']} img={t['image_size']} pal={t['palette_size']} hdr={t['header_size']}")
                    print(f"                GS TEX0=0x{t['gs_tex0']:016X}  TEX1=0x{t['gs_tex1']:016X}")
            else:
                print(f"    No TIM2 signature found. First 64 bytes:")
                dump_hex(dec, max_bytes=64, indent="      ")
        except Exception as e:
            print(f"    Decompression failed: {e}")

        pos += 4 + comp_size

def main():
    dat_path = "game_data/NETBIO00.DAT"
    if not os.path.exists(dat_path):
        print(f"Not found: {dat_path}")
        return

    with open(dat_path, 'rb') as f:
        outer = parse_afs(f, 0)
        inner = parse_afs(f, outer[0][0])
        print(f"romdata: {len(inner)} files")

        for idx in range(min(4, len(inner))):
            off, sz, name = inner[idx]
            if sz == 0 or sz > 10*1024*1024:
                continue
            f.seek(off)
            nbd_data = f.read(sz)

            print(f"\n{'='*60}")
            print(f"NBD [{idx}] {name}: {sz} bytes")

            chunks = parse_nbd_chunks(nbd_data)
            for c in chunks:
                print(f"  Chunk: {c['type']:4s}  offset=0x{c['offset']:06X}  size=0x{c['size']:06X}  count={c['count']}")

            for c in chunks:
                if c['type_raw'] == 0x00584554:  # TEX
                    chunk_data = nbd_data[c['offset']:c['offset']+c['size']]
                    analyze_tex_chunk(chunk_data, c['count'])

if __name__ == '__main__':
    main()
