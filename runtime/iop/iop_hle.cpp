#include "iop_hle.h"
#include "runtime/input/input.h"
#include "runtime/spu2/spu2.h"
#include "runtime/cdvd/cdvd.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <filesystem>

namespace reo {

namespace fs = std::filesystem;

IopHLE::IopHLE(Memory& ee_memory) : m_ee_memory(ee_memory) {
    fs::create_directories(m_mc_save_dir);
}

void IopHLE::sif_rpc_call(uint32_t module_id, uint32_t func_id, uint32_t send_buf,
                          uint32_t send_size, uint32_t recv_buf, uint32_t recv_size) {
    switch (module_id) {
        case SIF_PADMAN:
            hle_padman(func_id, send_buf, recv_buf);
            break;
        case SIF_MCSERV:
            hle_mcserv(func_id, send_buf, recv_buf);
            break;
        case SIF_CDVD:
            hle_cdvd(func_id, send_buf, recv_buf);
            break;
        case SIF_LIBSD:
            hle_libsd(func_id, send_buf, recv_buf);
            break;
        case SIF_INET:
        case SIF_NETCNF:
            hle_inet(func_id, send_buf, recv_buf);
            break;
        default:
            printf("[IOP] Unknown SIF RPC module: 0x%08X func: %d\n", module_id, func_id);
            break;
    }
}

void IopHLE::sif_dma_to_iop(uint32_t ee_addr, uint32_t iop_addr, uint32_t size) {
    uint8_t* src = m_ee_memory.get_pointer(ee_addr);
    uint8_t* dst = m_ee_memory.iop_ram() + (iop_addr & 0x1FFFFF);
    if (src && dst) {
        memcpy(dst, src, size);
    }
}

void IopHLE::sif_dma_to_ee(uint32_t iop_addr, uint32_t ee_addr, uint32_t size) {
    uint8_t* src = m_ee_memory.iop_ram() + (iop_addr & 0x1FFFFF);
    uint8_t* dst = m_ee_memory.get_pointer(ee_addr);
    if (src && dst) {
        memcpy(dst, src, size);
    }
}

int IopHLE::load_module(const std::string& name) {
    printf("[IOP] Load module: %s (HLE)\n", name.c_str());
    static int next_module = 100;
    return next_module++;
}

//
// PADMAN — Controller input
//
void IopHLE::hle_padman(uint32_t func, uint32_t send, uint32_t recv) {
    switch (func) {
        case 0: // padInit
            printf("[IOP:PAD] padInit\n");
            if (recv)
                m_ee_memory.write32(recv, 1); // Success
            break;

        case 1: // padEnd
            printf("[IOP:PAD] padEnd\n");
            break;

        case 2: // padPortOpen
        {
            printf("[IOP:PAD] padPortOpen\n");
            if (recv)
                m_ee_memory.write32(recv, 1); // Success
            break;
        }

        case 3: // padPortClose
            printf("[IOP:PAD] padPortClose\n");
            break;

        case 4: // padRead — return current controller state
        {
            if (!recv)
                break;

            // PS2 pad data format written to the recv buffer:
            // Offset 0: uint8_t  success (0 = ok)
            // Offset 1: uint8_t  mode (0x79 = DualShock2 analog, 0x41 = digital)
            // Offset 2: uint16_t buttons (inverted: 0 = pressed)
            // Offset 4: uint8_t  right_x
            // Offset 5: uint8_t  right_y
            // Offset 6: uint8_t  left_x
            // Offset 7: uint8_t  left_y
            // Offset 8+: pressure bytes

            uint8_t pad_data[32];
            memset(pad_data, 0, sizeof(pad_data));

            if (m_input) {
                const auto& pad = m_input->get_pad(0);

                pad_data[0] = 0x00; // Success
                pad_data[1] = 0x79; // DualShock2 analog mode (18 bytes of data)
                pad_data[2] = (uint8_t)(pad.buttons & 0xFF);
                pad_data[3] = (uint8_t)((pad.buttons >> 8) & 0xFF);
                pad_data[4] = pad.right_x;
                pad_data[5] = pad.right_y;
                pad_data[6] = pad.left_x;
                pad_data[7] = pad.left_y;

                // Pressure values (12 buttons)
                for (int i = 0; i < 12; i++) {
                    pad_data[8 + i] = pad.pressure[i];
                }
            } else {
                // No input system — return all buttons released
                pad_data[0] = 0x00;
                pad_data[1] = 0x79;
                pad_data[2] = 0xFF; // All released
                pad_data[3] = 0xFF;
                pad_data[4] = 0x80; // Center sticks
                pad_data[5] = 0x80;
                pad_data[6] = 0x80;
                pad_data[7] = 0x80;
            }

            // Write pad data to EE memory at recv address
            uint8_t* dst = m_ee_memory.get_pointer(recv);
            if (dst) {
                memcpy(dst, pad_data, sizeof(pad_data));
            }
            break;
        }

        case 5: // padSetMainMode
        {
            // Set analog/digital mode. We always report analog.
            if (recv)
                m_ee_memory.write32(recv, 1);
            break;
        }

        case 6: // padGetState — return pad connection state
        {
            // 6 = PAD_STATE_STABLE (connected and ready)
            if (recv)
                m_ee_memory.write32(recv, 6);
            break;
        }

        case 7: // padInfoMode
        {
            // Return mode info. 1 = current mode is DualShock2
            if (recv)
                m_ee_memory.write32(recv, 1);
            break;
        }

        case 8: // padSetActAlign — vibration motor setup
        {
            // Accept silently (no vibration support)
            if (recv)
                m_ee_memory.write32(recv, 1);
            break;
        }

        case 9: // padSetActDirect — vibration activation
        {
            // Accept silently
            if (recv)
                m_ee_memory.write32(recv, 1);
            break;
        }

        default:
            printf("[IOP:PAD] func=%d\n", func);
            break;
    }
}

//
// MCSERV — Memory card (save/load)
//
void IopHLE::hle_mcserv(uint32_t func, uint32_t send, uint32_t recv) {
    switch (func) {
        case 0: // mcInit
            printf("[IOP:MC] mcInit\n");
            if (recv)
                m_ee_memory.write32(recv, 0); // Success
            break;

        case 1: // mcGetInfo — check if card is inserted
        {
            // Return: type=2 (PS2 card), free=8000 (KB), format=1
            if (recv) {
                m_ee_memory.write32(recv + 0, 2);    // Type: PS2
                m_ee_memory.write32(recv + 4, 8000); // Free KB
                m_ee_memory.write32(recv + 8, 1);    // Formatted
                m_ee_memory.write32(recv + 12, 0);   // Return code: success
            }
            break;
        }

        case 4: // mcOpen
        {
            // Read filename from send buffer
            if (send) {
                uint8_t* name_ptr = m_ee_memory.get_pointer(send + 8);
                if (name_ptr) {
                    printf("[IOP:MC] mcOpen: %s\n", (char*)name_ptr);
                }
            }
            // Return file descriptor (always 1 for simplicity)
            if (recv)
                m_ee_memory.write32(recv, 1);
            break;
        }

        case 5: // mcClose
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;

        case 6: // mcRead
        {
            if (!send || !recv)
                break;
            uint32_t fd = m_ee_memory.read32(send);
            uint32_t buf_addr = m_ee_memory.read32(send + 4);
            uint32_t size = m_ee_memory.read32(send + 8);

            printf("[IOP:MC] mcRead: fd=%d buf=0x%08X size=%d\n", fd, buf_addr, size);

            // Try to read from local save directory
            fs::path save_file = fs::path(m_mc_save_dir) / "save.bin";
            if (fs::exists(save_file)) {
                std::ifstream file(save_file, std::ios::binary);
                uint8_t* dst = m_ee_memory.get_pointer(buf_addr);
                if (file && dst) {
                    file.read((char*)dst, size);
                    size = (uint32_t)file.gcount();
                }
            }
            if (recv)
                m_ee_memory.write32(recv, (uint32_t)size);
            break;
        }

        case 7: // mcWrite
        {
            if (!send)
                break;
            uint32_t fd = m_ee_memory.read32(send);
            uint32_t buf_addr = m_ee_memory.read32(send + 4);
            uint32_t size = m_ee_memory.read32(send + 8);

            printf("[IOP:MC] mcWrite: fd=%d buf=0x%08X size=%d\n", fd, buf_addr, size);

            // Write to local save directory
            fs::path save_file = fs::path(m_mc_save_dir) / "save.bin";
            uint8_t* src = m_ee_memory.get_pointer(buf_addr);
            if (src) {
                std::ofstream file(save_file, std::ios::binary);
                if (file) {
                    file.write((char*)src, size);
                }
            }
            if (recv)
                m_ee_memory.write32(recv, (uint32_t)size);
            break;
        }

        case 10: // mcMkDir
            printf("[IOP:MC] mcMkDir\n");
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;

        default:
            printf("[IOP:MC] func=%d\n", func);
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;
    }
}

//
// CDVD — Disc file access
//
void IopHLE::hle_cdvd(uint32_t func, uint32_t send, uint32_t recv) {
    switch (func) {
        case 0: // cdInit
            printf("[IOP:CDVD] cdInit\n");
            if (recv)
                m_ee_memory.write32(recv, 1); // Ready
            break;

        case 1: // cdRead (sector-based)
        {
            if (!send)
                break;
            uint32_t lba = m_ee_memory.read32(send);
            uint32_t sectors = m_ee_memory.read32(send + 4);
            uint32_t buf_addr = m_ee_memory.read32(send + 8);

            printf("[IOP:CDVD] cdRead: LBA=%d sectors=%d buf=0x%08X\n", lba, sectors, buf_addr);

            // Sector-based reads are rare — most game I/O uses sceCdReadFile
            if (m_cdvd) {
                uint8_t* dst = m_ee_memory.get_pointer(buf_addr);
                if (dst) {
                    m_cdvd->read_sectors(lba, sectors, dst);
                }
            }
            if (recv)
                m_ee_memory.write32(recv, 1); // Success
            break;
        }

        case 2: // cdStop
            printf("[IOP:CDVD] cdStop\n");
            if (recv)
                m_ee_memory.write32(recv, 1);
            break;

        case 4: // cdGetToc
            printf("[IOP:CDVD] cdGetToc\n");
            if (recv)
                m_ee_memory.write32(recv, 1);
            break;

        case 5: // cdReadFile — read a file by PS2 path
        {
            if (!send || !recv)
                break;

            // Send buffer: path string at offset 0 (or after some params)
            uint8_t* path_ptr = m_ee_memory.get_pointer(send);
            if (!path_ptr)
                break;

            // The send buffer layout depends on the game, but typically:
            //   offset 0: path string (null-terminated)
            // or:
            //   offset 0: uint32_t sectors
            //   offset 4: uint32_t dest_addr
            //   offset 8: path string

            // Try to detect format by checking if first bytes look like a path
            std::string ps2_path;
            if (path_ptr[0] == 'c' || path_ptr[0] == 'C' || path_ptr[0] == '\\') {
                ps2_path = (char*)path_ptr;
            } else {
                // Assume structured: read dest address then path
                uint32_t dest_addr = m_ee_memory.read32(send + 4);
                uint8_t* path_ptr2 = m_ee_memory.get_pointer(send + 8);
                if (path_ptr2) {
                    ps2_path = (char*)path_ptr2;
                }
            }

            if (!ps2_path.empty() && m_cdvd) {
                printf("[IOP:CDVD] cdReadFile: %s\n", ps2_path.c_str());
                std::vector<uint8_t> data;
                if (m_cdvd->read_file(ps2_path, data)) {
                    // Write file data to the destination buffer
                    uint32_t dest = m_ee_memory.read32(send + 4);
                    if (dest == 0)
                        dest = recv; // Fallback
                    uint8_t* dst = m_ee_memory.get_pointer(dest);
                    if (dst) {
                        memcpy(dst, data.data(), data.size());
                    }
                    m_ee_memory.write32(recv, (uint32_t)data.size());
                } else {
                    m_ee_memory.write32(recv, 0); // File not found
                }
            }
            break;
        }

        case 6: // cdSearchFile — check if file exists, return size
        {
            if (!send || !recv)
                break;

            uint8_t* path_ptr = m_ee_memory.get_pointer(send);
            if (!path_ptr)
                break;

            std::string ps2_path = (char*)path_ptr;
            printf("[IOP:CDVD] cdSearchFile: %s\n", ps2_path.c_str());

            if (m_cdvd && m_cdvd->file_exists(ps2_path)) {
                uint32_t size = m_cdvd->file_size(ps2_path);
                // Return struct: { uint32_t lba; uint32_t size; char name[]; }
                // For file-based access, LBA doesn't matter — set to 1
                m_ee_memory.write32(recv + 0, 1);    // LBA (fake)
                m_ee_memory.write32(recv + 4, size); // File size
                m_ee_memory.write32(recv + 8, 0);    // Date (unused)
                printf("[IOP:CDVD] Found: size=%u\n", size);
            } else {
                m_ee_memory.write32(recv + 0, 0); // Not found
                m_ee_memory.write32(recv + 4, 0);
                printf("[IOP:CDVD] Not found\n");
            }
            break;
        }

        case 7: // cdGetDiskType
            // 0x14 = PS2DVD
            if (recv)
                m_ee_memory.write32(recv, 0x14);
            break;

        case 12: // cdStatus
            // 0x0A = CDVD_STAT_PAUSE (ready)
            if (recv)
                m_ee_memory.write32(recv, 0x0A);
            break;

        default:
            printf("[IOP:CDVD] func=%d\n", func);
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;
    }
}

//
// LIBSD — SPU2 sound driver
//
void IopHLE::hle_libsd(uint32_t func, uint32_t send, uint32_t recv) {
    switch (func) {
        case 0: // sceSdInit
            printf("[IOP:SD] sceSdInit\n");
            if (recv)
                m_ee_memory.write32(recv, 0); // Success
            break;

        case 1: // sceSdSetParam — set voice/core parameters
        {
            if (!send)
                break;
            uint16_t entry = (uint16_t)m_ee_memory.read32(send);
            uint16_t value = (uint16_t)m_ee_memory.read32(send + 4);

            // Entry format: [15:10] = core/voice, [9:0] = parameter ID
            // Route to SPU2 register write
            if (m_spu2) {
                // Map libsd parameter entry to SPU2 register address
                uint32_t core = (entry >> 10) & 1;
                uint32_t voice = (entry >> 4) & 0x3F;
                uint32_t param = entry & 0xF;

                uint32_t addr = SPU2_REG_BASE + core * 0x400 + voice * 16 + param * 2;
                m_spu2->write_register(addr, value);
            }
            break;
        }

        case 2: // sceSdGetParam
        {
            if (!send || !recv)
                break;
            uint16_t entry = (uint16_t)m_ee_memory.read32(send);

            uint16_t value = 0;
            if (m_spu2) {
                uint32_t core = (entry >> 10) & 1;
                uint32_t voice = (entry >> 4) & 0x3F;
                uint32_t param = entry & 0xF;
                uint32_t addr = SPU2_REG_BASE + core * 0x400 + voice * 16 + param * 2;
                value = m_spu2->read_register(addr);
            }
            m_ee_memory.write32(recv, value);
            break;
        }

        case 4: // sceSdSetSwitch — key on/off
        {
            if (!send)
                break;
            uint16_t entry = (uint16_t)m_ee_memory.read32(send);
            uint32_t value = m_ee_memory.read32(send + 4);

            if (m_spu2) {
                uint32_t core = (entry >> 10) & 1;
                // Route key on/off to SPU2
                uint32_t param = entry & 0xFF;
                if (param == 0x1A) { // KON
                    m_spu2->write_register(SPU2_REG_BASE + core * 0x400 + SPU2_C_KON_LO,
                                           value & 0xFFFF);
                    m_spu2->write_register(SPU2_REG_BASE + core * 0x400 + SPU2_C_KON_HI,
                                           (value >> 16) & 0xFFFF);
                } else if (param == 0x1C) { // KOFF
                    m_spu2->write_register(SPU2_REG_BASE + core * 0x400 + SPU2_C_KOFF_LO,
                                           value & 0xFFFF);
                    m_spu2->write_register(SPU2_REG_BASE + core * 0x400 + SPU2_C_KOFF_HI,
                                           (value >> 16) & 0xFFFF);
                }
            }
            break;
        }

        case 11: // sceSdVoiceTrans — DMA transfer to SPU2 RAM
        {
            if (!send)
                break;
            uint16_t core_ch = (uint16_t)m_ee_memory.read32(send);
            uint16_t mode = (uint16_t)m_ee_memory.read32(send + 4);
            uint32_t iop_addr = m_ee_memory.read32(send + 8);
            uint32_t spu2_addr = m_ee_memory.read32(send + 12);
            uint32_t size = m_ee_memory.read32(send + 16);

            int core = core_ch & 1;

            printf("[IOP:SD] sceSdVoiceTrans: core=%d iop=0x%06X spu2=0x%06X size=%u\n", core,
                   iop_addr, spu2_addr, size);

            if (m_spu2) {
                // Transfer from IOP RAM to SPU2 RAM
                uint8_t* src = m_ee_memory.iop_ram() + (iop_addr & 0x1FFFFF);
                m_spu2->dma_write(core, src, spu2_addr, size);
            }

            if (recv)
                m_ee_memory.write32(recv, (uint32_t)size);
            break;
        }

        case 12: // sceSdVoiceTransStatus — check if DMA is done
            // Always done instantly in our implementation
            if (recv)
                m_ee_memory.write32(recv, 0); // 0 = completed
            break;

        case 14: // sceSdSetAddr — set voice start/loop address
        {
            if (!send)
                break;
            uint16_t entry = (uint16_t)m_ee_memory.read32(send);
            uint32_t value = m_ee_memory.read32(send + 4);
            // Route to SPU2 voice address registers
            // For now, just accept silently — the voice addresses are set
            // during key-on processing
            break;
        }

        default:
            printf("[IOP:SD] func=%d\n", func);
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;
    }
}

//
// INET — Network stack (for online play)
//
void IopHLE::hle_inet(uint32_t func, uint32_t send, uint32_t recv) {
    switch (func) {
        case 0: // sceInetInit
            printf("[IOP:NET] sceInetInit\n");
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;

        case 1: // sceInetCreate
            printf("[IOP:NET] sceInetCreate\n");
            // Return a socket ID (stub for now — online play not yet connected)
            if (recv)
                m_ee_memory.write32(recv, 1);
            break;

        case 2: // sceInetBind
            printf("[IOP:NET] sceInetBind\n");
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;

        case 5: // sceInetConnect
            printf("[IOP:NET] sceInetConnect (stub)\n");
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;

        case 8: // sceInetSend
            printf("[IOP:NET] sceInetSend (stub)\n");
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;

        case 9: // sceInetRecv
            // Return 0 bytes received (no data available)
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;

        case 15: // sceInetClose
            printf("[IOP:NET] sceInetClose\n");
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;

        default:
            printf("[IOP:NET] func=%d\n", func);
            if (recv)
                m_ee_memory.write32(recv, 0);
            break;
    }
}

} // namespace reo
