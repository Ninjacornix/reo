#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001101B0
// Address: 0x1101b0 - 0x110840
void sub_001101B0_0x1101b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001101B0_0x1101b0");
#endif

    ctx->pc = 0x1101b0u;

    // 0x1101b0: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x1101b0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1101b4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1101b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1101b8: 0x8503f  dsra32      $t2, $t0, 0
    ctx->pc = 0x1101b8u;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 8) >> (32 + 0));
    // 0x1101bc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1101bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1101c0: 0xa203c  dsll32      $a0, $t2, 0
    ctx->pc = 0x1101c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) << (32 + 0));
    // 0x1101c4: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1101c4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1101c8: 0x4810016  bgez        $a0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1101C8u;
    {
        const bool branch_taken_0x1101c8 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1101CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1101C8u;
            // 0x1101cc: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1101c8) {
            ctx->pc = 0x110224u;
            goto label_110224;
        }
    }
    ctx->pc = 0x1101D0u;
    // 0x1101d0: 0x8103c  dsll32      $v0, $t0, 0
    ctx->pc = 0x1101d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) << (32 + 0));
    // 0x1101d4: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1101d4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1101d8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1101d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1101dc: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1101dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1101e0: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1101e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1101e4: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x1101e4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x1101e8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1101e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1101ec: 0x41823  negu        $v1, $a0
    ctx->pc = 0x1101ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x1101f0: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1101f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1101f4: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x1101f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x1101f8: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x1101f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x1101fc: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x1101fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x110200: 0x2410ffff  addiu       $s0, $zero, -0x1
    ctx->pc = 0x110200u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x110204: 0x6103c  dsll32      $v0, $a2, 0
    ctx->pc = 0x110204u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
    // 0x110208: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x110208u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x11020c: 0xc43024  and         $a2, $a2, $a0
    ctx->pc = 0x11020cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 4));
    // 0x110210: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x110210u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x110214: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x110214u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x110218: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x110218u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11021c: 0xc34025  or          $t0, $a2, $v1
    ctx->pc = 0x11021cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x110220: 0x8503f  dsra32      $t2, $t0, 0
    ctx->pc = 0x110220u;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 8) >> (32 + 0));
label_110224:
    // 0x110224: 0x5203f  dsra32      $a0, $a1, 0
    ctx->pc = 0x110224u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x110228: 0x4810013  bgez        $a0, . + 4 + (0x13 << 2)
    ctx->pc = 0x110228u;
    {
        const bool branch_taken_0x110228 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x11022Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110228u;
            // 0x11022c: 0x42023  negu        $a0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110228) {
            ctx->pc = 0x110278u;
            goto label_110278;
        }
    }
    ctx->pc = 0x110230u;
    // 0x110230: 0x5103c  dsll32      $v0, $a1, 0
    ctx->pc = 0x110230u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 0));
    // 0x110234: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x110234u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x110238: 0x3c05ffff  lui         $a1, 0xFFFF
    ctx->pc = 0x110238u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65535 << 16));
    // 0x11023c: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x11023cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x110240: 0x21023  negu        $v0, $v0
    ctx->pc = 0x110240u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x110244: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x110244u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x110248: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x110248u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11024c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x11024cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x110250: 0xe33824  and         $a3, $a3, $v1
    ctx->pc = 0x110250u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & GPR_U64(ctx, 3));
    // 0x110254: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x110254u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x110258: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x110258u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x11025c: 0x7183c  dsll32      $v1, $a3, 0
    ctx->pc = 0x11025cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
    // 0x110260: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x110260u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x110264: 0xe53824  and         $a3, $a3, $a1
    ctx->pc = 0x110264u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x110268: 0x3182b  sltu        $v1, $zero, $v1
    ctx->pc = 0x110268u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x11026c: 0x832023  subu        $a0, $a0, $v1
    ctx->pc = 0x11026cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x110270: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x110270u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x110274: 0xe42825  or          $a1, $a3, $a0
    ctx->pc = 0x110274u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
label_110278:
    // 0x110278: 0x5483f  dsra32      $t1, $a1, 0
    ctx->pc = 0x110278u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x11027c: 0x8683c  dsll32      $t5, $t0, 0
    ctx->pc = 0x11027cu;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 8) << (32 + 0));
    // 0x110280: 0xd683f  dsra32      $t5, $t5, 0
    ctx->pc = 0x110280u;
    SET_GPR_S64(ctx, 13, GPR_S64(ctx, 13) >> (32 + 0));
    // 0x110284: 0xa503c  dsll32      $t2, $t2, 0
    ctx->pc = 0x110284u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) << (32 + 0));
    // 0x110288: 0xa503f  dsra32      $t2, $t2, 0
    ctx->pc = 0x110288u;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 10) >> (32 + 0));
    // 0x11028c: 0x5383c  dsll32      $a3, $a1, 0
    ctx->pc = 0x11028cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) << (32 + 0));
    // 0x110290: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x110290u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x110294: 0x152000b0  bnez        $t1, . + 4 + (0xB0 << 2)
    ctx->pc = 0x110294u;
    {
        const bool branch_taken_0x110294 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x110298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110294u;
            // 0x110298: 0x3a0c82d  daddu       $t9, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110294) {
            ctx->pc = 0x110558u;
            goto label_110558;
        }
    }
    ctx->pc = 0x11029Cu;
    // 0x11029c: 0x147102b  sltu        $v0, $t2, $a3
    ctx->pc = 0x11029cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x1102a0: 0x1040001f  beqz        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1102A0u;
    {
        const bool branch_taken_0x1102a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1102A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1102A0u;
            // 0x1102a4: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1102a0) {
            ctx->pc = 0x110320u;
            goto label_110320;
        }
    }
    ctx->pc = 0x1102A8u;
    // 0x1102a8: 0x47102b  sltu        $v0, $v0, $a3
    ctx->pc = 0x1102a8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x1102ac: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1102ACu;
    {
        const bool branch_taken_0x1102ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1102B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1102ACu;
            // 0x1102b0: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1102ac) {
            ctx->pc = 0x1102C8u;
            goto label_1102c8;
        }
    }
    ctx->pc = 0x1102B4u;
    // 0x1102b4: 0x2ce20100  sltiu       $v0, $a3, 0x100
    ctx->pc = 0x1102b4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1102b8: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1102b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1102bc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1102BCu;
    {
        const bool branch_taken_0x1102bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1102C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1102BCu;
            // 0x1102c0: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1102bc) {
            ctx->pc = 0x1102DCu;
            goto label_1102dc;
        }
    }
    ctx->pc = 0x1102C4u;
    // 0x1102c4: 0x0  nop
    ctx->pc = 0x1102c4u;
    // NOP
label_1102c8:
    // 0x1102c8: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x1102c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1102cc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1102ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1102d0: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1102d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1102d4: 0x47102b  sltu        $v0, $v0, $a3
    ctx->pc = 0x1102d4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x1102d8: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x1102d8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_1102dc:
    // 0x1102dc: 0x871806  srlv        $v1, $a3, $a0
    ctx->pc = 0x1102dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 4) & 0x1F));
    // 0x1102e0: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1102e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1102e4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1102e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1102e8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1102e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1102ec: 0x904282a0  lbu         $v0, -0x7D60($v0)
    ctx->pc = 0x1102ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294935200)));
    // 0x1102f0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1102f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1102f4: 0xa26023  subu        $t4, $a1, $v0
    ctx->pc = 0x1102f4u;
    SET_GPR_S32(ctx, 12, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1102f8: 0x11800006  beqz        $t4, . + 4 + (0x6 << 2)
    ctx->pc = 0x1102F8u;
    {
        const bool branch_taken_0x1102f8 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 0));
        ctx->pc = 0x1102FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1102F8u;
            // 0x1102fc: 0xac1023  subu        $v0, $a1, $t4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1102f8) {
            ctx->pc = 0x110314u;
            goto label_110314;
        }
    }
    ctx->pc = 0x110300u;
    // 0x110300: 0x18a1804  sllv        $v1, $t2, $t4
    ctx->pc = 0x110300u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 12) & 0x1F));
    // 0x110304: 0x4d1006  srlv        $v0, $t5, $v0
    ctx->pc = 0x110304u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 13), GPR_U32(ctx, 2) & 0x1F));
    // 0x110308: 0x18d6804  sllv        $t5, $t5, $t4
    ctx->pc = 0x110308u;
    SET_GPR_S32(ctx, 13, (int32_t)SLL32(GPR_U32(ctx, 13), GPR_U32(ctx, 12) & 0x1F));
    // 0x11030c: 0x625025  or          $t2, $v1, $v0
    ctx->pc = 0x11030cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x110310: 0x1873804  sllv        $a3, $a3, $t4
    ctx->pc = 0x110310u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 12) & 0x1F));
label_110314:
    // 0x110314: 0x73402  srl         $a2, $a3, 16
    ctx->pc = 0x110314u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x110318: 0x10000059  b           . + 4 + (0x59 << 2)
    ctx->pc = 0x110318u;
    {
        const bool branch_taken_0x110318 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11031Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110318u;
            // 0x11031c: 0x30e9ffff  andi        $t1, $a3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 9, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x110318) {
            ctx->pc = 0x110480u;
            goto label_110480;
        }
    }
    ctx->pc = 0x110320u;
label_110320:
    // 0x110320: 0x14e00009  bnez        $a3, . + 4 + (0x9 << 2)
    ctx->pc = 0x110320u;
    {
        const bool branch_taken_0x110320 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x110324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110320u;
            // 0x110324: 0x47102b  sltu        $v0, $v0, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x110320) {
            ctx->pc = 0x110348u;
            goto label_110348;
        }
    }
    ctx->pc = 0x110328u;
    // 0x110328: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x110328u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11032c: 0x50e00001  beql        $a3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x11032Cu;
    {
        const bool branch_taken_0x11032c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x11032c) {
            ctx->pc = 0x110330u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11032Cu;
            // 0x110330: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110334u;
            goto label_110334;
        }
    }
    ctx->pc = 0x110334u;
label_110334:
    // 0x110334: 0x49001b  divu        $zero, $v0, $t1
    ctx->pc = 0x110334u;
    { uint32_t divisor = GPR_U32(ctx, 9); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x110338: 0x1012  mflo        $v0
    ctx->pc = 0x110338u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x11033c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x11033cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110340: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x110340u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x110344: 0x47102b  sltu        $v0, $v0, $a3
    ctx->pc = 0x110344u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
label_110348:
    // 0x110348: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x110348u;
    {
        const bool branch_taken_0x110348 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11034Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110348u;
            // 0x11034c: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110348) {
            ctx->pc = 0x110360u;
            goto label_110360;
        }
    }
    ctx->pc = 0x110350u;
    // 0x110350: 0x2ce20100  sltiu       $v0, $a3, 0x100
    ctx->pc = 0x110350u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x110354: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x110354u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x110358: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x110358u;
    {
        const bool branch_taken_0x110358 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11035Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110358u;
            // 0x11035c: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110358) {
            ctx->pc = 0x110374u;
            goto label_110374;
        }
    }
    ctx->pc = 0x110360u;
label_110360:
    // 0x110360: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x110360u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x110364: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x110364u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x110368: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x110368u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x11036c: 0x47102b  sltu        $v0, $v0, $a3
    ctx->pc = 0x11036cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x110370: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x110370u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_110374:
    // 0x110374: 0x871806  srlv        $v1, $a3, $a0
    ctx->pc = 0x110374u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 4) & 0x1F));
    // 0x110378: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x110378u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11037c: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x11037cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x110380: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x110380u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x110384: 0x904282a0  lbu         $v0, -0x7D60($v0)
    ctx->pc = 0x110384u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294935200)));
    // 0x110388: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x110388u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x11038c: 0xa26023  subu        $t4, $a1, $v0
    ctx->pc = 0x11038cu;
    SET_GPR_S32(ctx, 12, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x110390: 0x15800005  bnez        $t4, . + 4 + (0x5 << 2)
    ctx->pc = 0x110390u;
    {
        const bool branch_taken_0x110390 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x110394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110390u;
            // 0x110394: 0xac7823  subu        $t7, $a1, $t4 (Delay Slot)
        SET_GPR_S32(ctx, 15, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110390) {
            ctx->pc = 0x1103A8u;
            goto label_1103a8;
        }
    }
    ctx->pc = 0x110398u;
    // 0x110398: 0x1475023  subu        $t2, $t2, $a3
    ctx->pc = 0x110398u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 10), GPR_U32(ctx, 7)));
    // 0x11039c: 0x72c02  srl         $a1, $a3, 16
    ctx->pc = 0x11039cu;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x1103a0: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1103A0u;
    {
        const bool branch_taken_0x1103a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1103A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1103A0u;
            // 0x1103a4: 0x30eeffff  andi        $t6, $a3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 14, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1103a0) {
            ctx->pc = 0x110478u;
            goto label_110478;
        }
    }
    ctx->pc = 0x1103A8u;
label_1103a8:
    // 0x1103a8: 0x18a1804  sllv        $v1, $t2, $t4
    ctx->pc = 0x1103a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 12) & 0x1F));
    // 0x1103ac: 0x1ed1006  srlv        $v0, $t5, $t7
    ctx->pc = 0x1103acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 13), GPR_U32(ctx, 15) & 0x1F));
    // 0x1103b0: 0x18d6804  sllv        $t5, $t5, $t4
    ctx->pc = 0x1103b0u;
    SET_GPR_S32(ctx, 13, (int32_t)SLL32(GPR_U32(ctx, 13), GPR_U32(ctx, 12) & 0x1F));
    // 0x1103b4: 0x1ea2006  srlv        $a0, $t2, $t7
    ctx->pc = 0x1103b4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 15) & 0x1F));
    // 0x1103b8: 0x625025  or          $t2, $v1, $v0
    ctx->pc = 0x1103b8u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1103bc: 0x1873804  sllv        $a3, $a3, $t4
    ctx->pc = 0x1103bcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 12) & 0x1F));
    // 0x1103c0: 0x72c02  srl         $a1, $a3, 16
    ctx->pc = 0x1103c0u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 7), 16));
    // 0x1103c4: 0x85001b  divu        $zero, $a0, $a1
    ctx->pc = 0x1103c4u;
    { uint32_t divisor = GPR_U32(ctx, 5); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
    // 0x1103c8: 0xa2402  srl         $a0, $t2, 16
    ctx->pc = 0x1103c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
    // 0x1103cc: 0x30eeffff  andi        $t6, $a3, 0xFFFF
    ctx->pc = 0x1103ccu;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
    // 0x1103d0: 0xa0482d  daddu       $t1, $a1, $zero
    ctx->pc = 0x1103d0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1103d4: 0x51200001  beql        $t1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1103D4u;
    {
        const bool branch_taken_0x1103d4 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x1103d4) {
            ctx->pc = 0x1103D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1103D4u;
            // 0x1103d8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1103DCu;
            goto label_1103dc;
        }
    }
    ctx->pc = 0x1103DCu;
label_1103dc:
    // 0x1103dc: 0x1012  mflo        $v0
    ctx->pc = 0x1103dcu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1103e0: 0x1810  mfhi        $v1
    ctx->pc = 0x1103e0u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1103e4: 0x4e4018  mult        $t0, $v0, $t6
    ctx->pc = 0x1103e4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 14); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x1103e8: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1103e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1103ec: 0x643025  or          $a2, $v1, $a0
    ctx->pc = 0x1103ecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1103f0: 0xc8102b  sltu        $v0, $a2, $t0
    ctx->pc = 0x1103f0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x1103f4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1103F4u;
    {
        const bool branch_taken_0x1103f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1103F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1103F4u;
            // 0x1103f8: 0x1c0782d  daddu       $t7, $t6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1103f4) {
            ctx->pc = 0x110420u;
            goto label_110420;
        }
    }
    ctx->pc = 0x1103FCu;
    // 0x1103fc: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x1103fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x110400: 0xc7102b  sltu        $v0, $a2, $a3
    ctx->pc = 0x110400u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x110404: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x110404u;
    {
        const bool branch_taken_0x110404 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x110404) {
            ctx->pc = 0x110408u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110404u;
            // 0x110408: 0xc83023  subu        $a2, $a2, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110424u;
            goto label_110424;
        }
    }
    ctx->pc = 0x11040Cu;
    // 0x11040c: 0xc8102b  sltu        $v0, $a2, $t0
    ctx->pc = 0x11040cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110410: 0xc71821  addu        $v1, $a2, $a3
    ctx->pc = 0x110410u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x110414: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x110414u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x110418: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x110418u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x11041c: 0x0  nop
    ctx->pc = 0x11041cu;
    // NOP
label_110420:
    // 0x110420: 0xc83023  subu        $a2, $a2, $t0
    ctx->pc = 0x110420u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
label_110424:
    // 0x110424: 0x3144ffff  andi        $a0, $t2, 0xFFFF
    ctx->pc = 0x110424u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
    // 0x110428: 0xc9001b  divu        $zero, $a2, $t1
    ctx->pc = 0x110428u;
    { uint32_t divisor = GPR_U32(ctx, 9); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 6) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 6) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,6); } }
    // 0x11042c: 0x51200001  beql        $t1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x11042Cu;
    {
        const bool branch_taken_0x11042c = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x11042c) {
            ctx->pc = 0x110430u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11042Cu;
            // 0x110430: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110434u;
            goto label_110434;
        }
    }
    ctx->pc = 0x110434u;
label_110434:
    // 0x110434: 0x1012  mflo        $v0
    ctx->pc = 0x110434u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110438: 0x1810  mfhi        $v1
    ctx->pc = 0x110438u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x11043c: 0x4f4018  mult        $t0, $v0, $t7
    ctx->pc = 0x11043cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 15); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x110440: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110440u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x110444: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x110444u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110448: 0x88102b  sltu        $v0, $a0, $t0
    ctx->pc = 0x110448u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x11044c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x11044Cu;
    {
        const bool branch_taken_0x11044c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11044Cu;
            // 0x110450: 0x885023  subu        $t2, $a0, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11044c) {
            ctx->pc = 0x110478u;
            goto label_110478;
        }
    }
    ctx->pc = 0x110454u;
    // 0x110454: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x110454u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x110458: 0x87102b  sltu        $v0, $a0, $a3
    ctx->pc = 0x110458u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x11045c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11045Cu;
    {
        const bool branch_taken_0x11045c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11045Cu;
            // 0x110460: 0x885023  subu        $t2, $a0, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11045c) {
            ctx->pc = 0x110478u;
            goto label_110478;
        }
    }
    ctx->pc = 0x110464u;
    // 0x110464: 0x88102b  sltu        $v0, $a0, $t0
    ctx->pc = 0x110464u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110468: 0x871821  addu        $v1, $a0, $a3
    ctx->pc = 0x110468u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x11046c: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x11046cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x110470: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x110470u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x110474: 0x885023  subu        $t2, $a0, $t0
    ctx->pc = 0x110474u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
label_110478:
    // 0x110478: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x110478u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11047c: 0x1c0482d  daddu       $t1, $t6, $zero
    ctx->pc = 0x11047cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
label_110480:
    // 0x110480: 0x146001b  divu        $zero, $t2, $a2
    ctx->pc = 0x110480u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,10); } }
    // 0x110484: 0xd2402  srl         $a0, $t5, 16
    ctx->pc = 0x110484u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 13), 16));
    // 0x110488: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110488u;
    {
        const bool branch_taken_0x110488 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x110488) {
            ctx->pc = 0x11048Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110488u;
            // 0x11048c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110490u;
            goto label_110490;
        }
    }
    ctx->pc = 0x110490u;
label_110490:
    // 0x110490: 0x1012  mflo        $v0
    ctx->pc = 0x110490u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110494: 0x1810  mfhi        $v1
    ctx->pc = 0x110494u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110498: 0x494018  mult        $t0, $v0, $t1
    ctx->pc = 0x110498u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x11049c: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x11049cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1104a0: 0x642825  or          $a1, $v1, $a0
    ctx->pc = 0x1104a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1104a4: 0xa8102b  sltu        $v0, $a1, $t0
    ctx->pc = 0x1104a4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x1104a8: 0x5040000a  beql        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x1104A8u;
    {
        const bool branch_taken_0x1104a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1104a8) {
            ctx->pc = 0x1104ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1104A8u;
            // 0x1104ac: 0xa82823  subu        $a1, $a1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1104D4u;
            goto label_1104d4;
        }
    }
    ctx->pc = 0x1104B0u;
    // 0x1104b0: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1104b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1104b4: 0xa7102b  sltu        $v0, $a1, $a3
    ctx->pc = 0x1104b4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x1104b8: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x1104B8u;
    {
        const bool branch_taken_0x1104b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1104b8) {
            ctx->pc = 0x1104BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1104B8u;
            // 0x1104bc: 0xa82823  subu        $a1, $a1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1104D4u;
            goto label_1104d4;
        }
    }
    ctx->pc = 0x1104C0u;
    // 0x1104c0: 0xa8102b  sltu        $v0, $a1, $t0
    ctx->pc = 0x1104c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x1104c4: 0xa71821  addu        $v1, $a1, $a3
    ctx->pc = 0x1104c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1104c8: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x1104c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x1104cc: 0x62280b  movn        $a1, $v1, $v0
    ctx->pc = 0x1104ccu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 3));
    // 0x1104d0: 0xa82823  subu        $a1, $a1, $t0
    ctx->pc = 0x1104d0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
label_1104d4:
    // 0x1104d4: 0x31a4ffff  andi        $a0, $t5, 0xFFFF
    ctx->pc = 0x1104d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 13) & (uint64_t)(uint16_t)65535);
    // 0x1104d8: 0xa6001b  divu        $zero, $a1, $a2
    ctx->pc = 0x1104d8u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,5); } }
    // 0x1104dc: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1104DCu;
    {
        const bool branch_taken_0x1104dc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1104dc) {
            ctx->pc = 0x1104E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1104DCu;
            // 0x1104e0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1104E4u;
            goto label_1104e4;
        }
    }
    ctx->pc = 0x1104E4u;
label_1104e4:
    // 0x1104e4: 0x1012  mflo        $v0
    ctx->pc = 0x1104e4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1104e8: 0x1810  mfhi        $v1
    ctx->pc = 0x1104e8u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1104ec: 0x494018  mult        $t0, $v0, $t1
    ctx->pc = 0x1104ecu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x1104f0: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1104f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1104f4: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1104f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1104f8: 0x88102b  sltu        $v0, $a0, $t0
    ctx->pc = 0x1104f8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x1104fc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1104FCu;
    {
        const bool branch_taken_0x1104fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1104fc) {
            ctx->pc = 0x110520u;
            goto label_110520;
        }
    }
    ctx->pc = 0x110504u;
    // 0x110504: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x110504u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x110508: 0x87102b  sltu        $v0, $a0, $a3
    ctx->pc = 0x110508u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x11050c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11050Cu;
    {
        const bool branch_taken_0x11050c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11050Cu;
            // 0x110510: 0x88102b  sltu        $v0, $a0, $t0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11050c) {
            ctx->pc = 0x110520u;
            goto label_110520;
        }
    }
    ctx->pc = 0x110514u;
    // 0x110514: 0x871821  addu        $v1, $a0, $a3
    ctx->pc = 0x110514u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x110518: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x110518u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x11051c: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x11051cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_110520:
    // 0x110520: 0x132000ac  beqz        $t9, . + 4 + (0xAC << 2)
    ctx->pc = 0x110520u;
    {
        const bool branch_taken_0x110520 = (GPR_U64(ctx, 25) == GPR_U64(ctx, 0));
        ctx->pc = 0x110524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110520u;
            // 0x110524: 0x886823  subu        $t5, $a0, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 13, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110520) {
            ctx->pc = 0x1107D4u;
            goto label_1107d4;
        }
    }
    ctx->pc = 0x110528u;
    // 0x110528: 0x18d1006  srlv        $v0, $t5, $t4
    ctx->pc = 0x110528u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 13), GPR_U32(ctx, 12) & 0x1F));
    // 0x11052c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x11052cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x110530: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x110530u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x110534: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x110534u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x110538: 0x1635824  and         $t3, $t3, $v1
    ctx->pc = 0x110538u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 3));
    // 0x11053c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x11053cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x110540: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x110540u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x110544: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x110544u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x110548: 0x1625825  or          $t3, $t3, $v0
    ctx->pc = 0x110548u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | GPR_U64(ctx, 2));
    // 0x11054c: 0x100000a0  b           . + 4 + (0xA0 << 2)
    ctx->pc = 0x11054Cu;
    {
        const bool branch_taken_0x11054c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11054Cu;
            // 0x110550: 0x1635824  and         $t3, $t3, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11054c) {
            ctx->pc = 0x1107D0u;
            goto label_1107d0;
        }
    }
    ctx->pc = 0x110554u;
    // 0x110554: 0x0  nop
    ctx->pc = 0x110554u;
    // NOP
label_110558:
    // 0x110558: 0x149102b  sltu        $v0, $t2, $t1
    ctx->pc = 0x110558u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x11055c: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x11055Cu;
    {
        const bool branch_taken_0x11055c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11055Cu;
            // 0x110560: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11055c) {
            ctx->pc = 0x110598u;
            goto label_110598;
        }
    }
    ctx->pc = 0x110564u;
    // 0x110564: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x110564u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x110568: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x110568u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11056c: 0xd103c  dsll32      $v0, $t5, 0
    ctx->pc = 0x11056cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 13) << (32 + 0));
    // 0x110570: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x110570u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x110574: 0x1635824  and         $t3, $t3, $v1
    ctx->pc = 0x110574u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 3));
    // 0x110578: 0x1625825  or          $t3, $t3, $v0
    ctx->pc = 0x110578u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | GPR_U64(ctx, 2));
    // 0x11057c: 0xa103c  dsll32      $v0, $t2, 0
    ctx->pc = 0x11057cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) << (32 + 0));
    // 0x110580: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x110580u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x110584: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x110584u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x110588: 0x1635824  and         $t3, $t3, $v1
    ctx->pc = 0x110588u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 3));
    // 0x11058c: 0x1625825  or          $t3, $t3, $v0
    ctx->pc = 0x11058cu;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | GPR_U64(ctx, 2));
    // 0x110590: 0x10000090  b           . + 4 + (0x90 << 2)
    ctx->pc = 0x110590u;
    {
        const bool branch_taken_0x110590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110590u;
            // 0x110594: 0xffab0000  sd          $t3, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110590) {
            ctx->pc = 0x1107D4u;
            goto label_1107d4;
        }
    }
    ctx->pc = 0x110598u;
label_110598:
    // 0x110598: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x110598u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x11059c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11059Cu;
    {
        const bool branch_taken_0x11059c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1105A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11059Cu;
            // 0x1105a0: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11059c) {
            ctx->pc = 0x1105B8u;
            goto label_1105b8;
        }
    }
    ctx->pc = 0x1105A4u;
    // 0x1105a4: 0x2d220100  sltiu       $v0, $t1, 0x100
    ctx->pc = 0x1105a4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1105a8: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1105a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1105ac: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1105ACu;
    {
        const bool branch_taken_0x1105ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1105B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1105ACu;
            // 0x1105b0: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1105ac) {
            ctx->pc = 0x1105CCu;
            goto label_1105cc;
        }
    }
    ctx->pc = 0x1105B4u;
    // 0x1105b4: 0x0  nop
    ctx->pc = 0x1105b4u;
    // NOP
label_1105b8:
    // 0x1105b8: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x1105b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1105bc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1105bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1105c0: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1105c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1105c4: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x1105c4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x1105c8: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x1105c8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_1105cc:
    // 0x1105cc: 0x891806  srlv        $v1, $t1, $a0
    ctx->pc = 0x1105ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), GPR_U32(ctx, 4) & 0x1F));
    // 0x1105d0: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1105d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1105d4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1105d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1105d8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1105d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1105dc: 0x904282a0  lbu         $v0, -0x7D60($v0)
    ctx->pc = 0x1105dcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294935200)));
    // 0x1105e0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1105e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1105e4: 0xa26023  subu        $t4, $a1, $v0
    ctx->pc = 0x1105e4u;
    SET_GPR_S32(ctx, 12, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1105e8: 0x15800019  bnez        $t4, . + 4 + (0x19 << 2)
    ctx->pc = 0x1105E8u;
    {
        const bool branch_taken_0x1105e8 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x1105ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1105E8u;
            // 0x1105ec: 0xac7823  subu        $t7, $a1, $t4 (Delay Slot)
        SET_GPR_S32(ctx, 15, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1105e8) {
            ctx->pc = 0x110650u;
            goto label_110650;
        }
    }
    ctx->pc = 0x1105F0u;
    // 0x1105f0: 0x12a102b  sltu        $v0, $t1, $t2
    ctx->pc = 0x1105f0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)GPR_U64(ctx, 10)) ? 1 : 0);
    // 0x1105f4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1105F4u;
    {
        const bool branch_taken_0x1105f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1105F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1105F4u;
            // 0x1105f8: 0x1a71023  subu        $v0, $t5, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 13), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1105f4) {
            ctx->pc = 0x110608u;
            goto label_110608;
        }
    }
    ctx->pc = 0x1105FCu;
    // 0x1105fc: 0x1a7102b  sltu        $v0, $t5, $a3
    ctx->pc = 0x1105fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 13) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x110600: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x110600u;
    {
        const bool branch_taken_0x110600 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110600u;
            // 0x110604: 0x1a71023  subu        $v0, $t5, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 13), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110600) {
            ctx->pc = 0x110618u;
            goto label_110618;
        }
    }
    ctx->pc = 0x110608u;
label_110608:
    // 0x110608: 0x1492023  subu        $a0, $t2, $t1
    ctx->pc = 0x110608u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x11060c: 0x1a2182b  sltu        $v1, $t5, $v0
    ctx->pc = 0x11060cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 13) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x110610: 0x40682d  daddu       $t5, $v0, $zero
    ctx->pc = 0x110610u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110614: 0x835023  subu        $t2, $a0, $v1
    ctx->pc = 0x110614u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_110618:
    // 0x110618: 0x1320006e  beqz        $t9, . + 4 + (0x6E << 2)
    ctx->pc = 0x110618u;
    {
        const bool branch_taken_0x110618 = (GPR_U64(ctx, 25) == GPR_U64(ctx, 0));
        ctx->pc = 0x11061Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110618u;
            // 0x11061c: 0xd103c  dsll32      $v0, $t5, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 13) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110618) {
            ctx->pc = 0x1107D4u;
            goto label_1107d4;
        }
    }
    ctx->pc = 0x110620u;
    // 0x110620: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x110620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x110624: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x110624u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x110628: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x110628u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x11062c: 0x1635824  and         $t3, $t3, $v1
    ctx->pc = 0x11062cu;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 3));
    // 0x110630: 0x1625825  or          $t3, $t3, $v0
    ctx->pc = 0x110630u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | GPR_U64(ctx, 2));
    // 0x110634: 0xa103c  dsll32      $v0, $t2, 0
    ctx->pc = 0x110634u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) << (32 + 0));
    // 0x110638: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x110638u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x11063c: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x11063cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x110640: 0x1635824  and         $t3, $t3, $v1
    ctx->pc = 0x110640u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 3));
    // 0x110644: 0x10000062  b           . + 4 + (0x62 << 2)
    ctx->pc = 0x110644u;
    {
        const bool branch_taken_0x110644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110644u;
            // 0x110648: 0x1625825  or          $t3, $t3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110644) {
            ctx->pc = 0x1107D0u;
            goto label_1107d0;
        }
    }
    ctx->pc = 0x11064Cu;
    // 0x11064c: 0x0  nop
    ctx->pc = 0x11064cu;
    // NOP
label_110650:
    // 0x110650: 0x18a2804  sllv        $a1, $t2, $t4
    ctx->pc = 0x110650u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 12) & 0x1F));
    // 0x110654: 0x1892004  sllv        $a0, $t1, $t4
    ctx->pc = 0x110654u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 12) & 0x1F));
    // 0x110658: 0x1e71006  srlv        $v0, $a3, $t7
    ctx->pc = 0x110658u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 15) & 0x1F));
    // 0x11065c: 0x1ed1806  srlv        $v1, $t5, $t7
    ctx->pc = 0x11065cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 13), GPR_U32(ctx, 15) & 0x1F));
    // 0x110660: 0x18d6804  sllv        $t5, $t5, $t4
    ctx->pc = 0x110660u;
    SET_GPR_S32(ctx, 13, (int32_t)SLL32(GPR_U32(ctx, 13), GPR_U32(ctx, 12) & 0x1F));
    // 0x110664: 0x824825  or          $t1, $a0, $v0
    ctx->pc = 0x110664u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x110668: 0x1ea2006  srlv        $a0, $t2, $t7
    ctx->pc = 0x110668u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 15) & 0x1F));
    // 0x11066c: 0x1873804  sllv        $a3, $a3, $t4
    ctx->pc = 0x11066cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 12) & 0x1F));
    // 0x110670: 0xa35025  or          $t2, $a1, $v1
    ctx->pc = 0x110670u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x110674: 0x93402  srl         $a2, $t1, 16
    ctx->pc = 0x110674u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x110678: 0x86001b  divu        $zero, $a0, $a2
    ctx->pc = 0x110678u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
    // 0x11067c: 0xa2402  srl         $a0, $t2, 16
    ctx->pc = 0x11067cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
    // 0x110680: 0x3125ffff  andi        $a1, $t1, 0xFFFF
    ctx->pc = 0x110680u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x110684: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110684u;
    {
        const bool branch_taken_0x110684 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x110684) {
            ctx->pc = 0x110688u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110684u;
            // 0x110688: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x11068Cu;
            goto label_11068c;
        }
    }
    ctx->pc = 0x11068Cu;
label_11068c:
    // 0x11068c: 0x1012  mflo        $v0
    ctx->pc = 0x11068cu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110690: 0x1810  mfhi        $v1
    ctx->pc = 0x110690u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110694: 0x40702d  daddu       $t6, $v0, $zero
    ctx->pc = 0x110694u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110698: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110698u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x11069c: 0x1c54018  mult        $t0, $t6, $a1
    ctx->pc = 0x11069cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 14) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x1106a0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1106a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1106a4: 0x68102b  sltu        $v0, $v1, $t0
    ctx->pc = 0x1106a4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x1106a8: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x1106A8u;
    {
        const bool branch_taken_0x1106a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1106a8) {
            ctx->pc = 0x1106ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1106A8u;
            // 0x1106ac: 0x681823  subu        $v1, $v1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1106DCu;
            goto label_1106dc;
        }
    }
    ctx->pc = 0x1106B0u;
    // 0x1106b0: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x1106b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1106b4: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x1106b4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x1106b8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1106B8u;
    {
        const bool branch_taken_0x1106b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1106BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1106B8u;
            // 0x1106bc: 0x25ceffff  addiu       $t6, $t6, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1106b8) {
            ctx->pc = 0x1106D8u;
            goto label_1106d8;
        }
    }
    ctx->pc = 0x1106C0u;
    // 0x1106c0: 0x68102b  sltu        $v0, $v1, $t0
    ctx->pc = 0x1106c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x1106c4: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1106C4u;
    {
        const bool branch_taken_0x1106c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1106c4) {
            ctx->pc = 0x1106C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1106C4u;
            // 0x1106c8: 0x681823  subu        $v1, $v1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1106DCu;
            goto label_1106dc;
        }
    }
    ctx->pc = 0x1106CCu;
    // 0x1106cc: 0x25ceffff  addiu       $t6, $t6, -0x1
    ctx->pc = 0x1106ccu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 4294967295));
    // 0x1106d0: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x1106d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1106d4: 0x0  nop
    ctx->pc = 0x1106d4u;
    // NOP
label_1106d8:
    // 0x1106d8: 0x681823  subu        $v1, $v1, $t0
    ctx->pc = 0x1106d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
label_1106dc:
    // 0x1106dc: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1106DCu;
    {
        const bool branch_taken_0x1106dc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1106dc) {
            ctx->pc = 0x1106E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1106DCu;
            // 0x1106e0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1106E4u;
            goto label_1106e4;
        }
    }
    ctx->pc = 0x1106E4u;
label_1106e4:
    // 0x1106e4: 0x66001b  divu        $zero, $v1, $a2
    ctx->pc = 0x1106e4u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x1106e8: 0x3144ffff  andi        $a0, $t2, 0xFFFF
    ctx->pc = 0x1106e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
    // 0x1106ec: 0x1012  mflo        $v0
    ctx->pc = 0x1106ecu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1106f0: 0x1810  mfhi        $v1
    ctx->pc = 0x1106f0u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1106f4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1106f4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1106f8: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1106f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1106fc: 0xc54018  mult        $t0, $a2, $a1
    ctx->pc = 0x1106fcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x110700: 0x642825  or          $a1, $v1, $a0
    ctx->pc = 0x110700u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110704: 0xa8102b  sltu        $v0, $a1, $t0
    ctx->pc = 0x110704u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110708: 0x5040000b  beql        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x110708u;
    {
        const bool branch_taken_0x110708 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110708) {
            ctx->pc = 0x11070Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110708u;
            // 0x11070c: 0xa82823  subu        $a1, $a1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110738u;
            goto label_110738;
        }
    }
    ctx->pc = 0x110710u;
    // 0x110710: 0xa92821  addu        $a1, $a1, $t1
    ctx->pc = 0x110710u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
    // 0x110714: 0xa9102b  sltu        $v0, $a1, $t1
    ctx->pc = 0x110714u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110718: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x110718u;
    {
        const bool branch_taken_0x110718 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11071Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110718u;
            // 0x11071c: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110718) {
            ctx->pc = 0x110734u;
            goto label_110734;
        }
    }
    ctx->pc = 0x110720u;
    // 0x110720: 0xa8102b  sltu        $v0, $a1, $t0
    ctx->pc = 0x110720u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110724: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x110724u;
    {
        const bool branch_taken_0x110724 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110724) {
            ctx->pc = 0x110728u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110724u;
            // 0x110728: 0xa82823  subu        $a1, $a1, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110738u;
            goto label_110738;
        }
    }
    ctx->pc = 0x11072Cu;
    // 0x11072c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x11072cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x110730: 0xa92821  addu        $a1, $a1, $t1
    ctx->pc = 0x110730u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 9)));
label_110734:
    // 0x110734: 0xa82823  subu        $a1, $a1, $t0
    ctx->pc = 0x110734u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
label_110738:
    // 0x110738: 0xe1400  sll         $v0, $t6, 16
    ctx->pc = 0x110738u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 14), 16));
    // 0x11073c: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x11073cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x110740: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x110740u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110744: 0x470019  multu       $v0, $a3
    ctx->pc = 0x110744u;
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x110748: 0x3010  mfhi        $a2
    ctx->pc = 0x110748u;
    SET_GPR_U64(ctx, 6, ctx->hi);
    // 0x11074c: 0x4012  mflo        $t0
    ctx->pc = 0x11074cu;
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x110750: 0x146182b  sltu        $v1, $t2, $a2
    ctx->pc = 0x110750u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x110754: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x110754u;
    {
        const bool branch_taken_0x110754 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x110758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110754u;
            // 0x110758: 0x1071023  subu        $v0, $t0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110754) {
            ctx->pc = 0x110770u;
            goto label_110770;
        }
    }
    ctx->pc = 0x11075Cu;
    // 0x11075c: 0x14ca0008  bne         $a2, $t2, . + 4 + (0x8 << 2)
    ctx->pc = 0x11075Cu;
    {
        const bool branch_taken_0x11075c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 10));
        ctx->pc = 0x110760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11075Cu;
            // 0x110760: 0x1a8102b  sltu        $v0, $t5, $t0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 13) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11075c) {
            ctx->pc = 0x110780u;
            goto label_110780;
        }
    }
    ctx->pc = 0x110764u;
    // 0x110764: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x110764u;
    {
        const bool branch_taken_0x110764 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110764u;
            // 0x110768: 0x1071023  subu        $v0, $t0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110764) {
            ctx->pc = 0x110780u;
            goto label_110780;
        }
    }
    ctx->pc = 0x11076Cu;
    // 0x11076c: 0x0  nop
    ctx->pc = 0x11076cu;
    // NOP
label_110770:
    // 0x110770: 0xc92023  subu        $a0, $a2, $t1
    ctx->pc = 0x110770u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0x110774: 0x102182b  sltu        $v1, $t0, $v0
    ctx->pc = 0x110774u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x110778: 0x40402d  daddu       $t0, $v0, $zero
    ctx->pc = 0x110778u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11077c: 0x833023  subu        $a2, $a0, $v1
    ctx->pc = 0x11077cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_110780:
    // 0x110780: 0x13200014  beqz        $t9, . + 4 + (0x14 << 2)
    ctx->pc = 0x110780u;
    {
        const bool branch_taken_0x110780 = (GPR_U64(ctx, 25) == GPR_U64(ctx, 0));
        ctx->pc = 0x110784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110780u;
            // 0x110784: 0x1a82023  subu        $a0, $t5, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 13), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110780) {
            ctx->pc = 0x1107D4u;
            goto label_1107d4;
        }
    }
    ctx->pc = 0x110788u;
    // 0x110788: 0xa62823  subu        $a1, $a1, $a2
    ctx->pc = 0x110788u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x11078c: 0x1a4182b  sltu        $v1, $t5, $a0
    ctx->pc = 0x11078cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 13) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x110790: 0xa35023  subu        $t2, $a1, $v1
    ctx->pc = 0x110790u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x110794: 0x1ea1004  sllv        $v0, $t2, $t7
    ctx->pc = 0x110794u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 15) & 0x1F));
    // 0x110798: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x110798u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11079c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x11079cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1107a0: 0x1842006  srlv        $a0, $a0, $t4
    ctx->pc = 0x1107a0u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), GPR_U32(ctx, 12) & 0x1F));
    // 0x1107a4: 0x1635824  and         $t3, $t3, $v1
    ctx->pc = 0x1107a4u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 3));
    // 0x1107a8: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1107a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1107ac: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x1107acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x1107b0: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x1107b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x1107b4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1107b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1107b8: 0x18a1806  srlv        $v1, $t2, $t4
    ctx->pc = 0x1107b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 12) & 0x1F));
    // 0x1107bc: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1107bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1107c0: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1107c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1107c4: 0x1625825  or          $t3, $t3, $v0
    ctx->pc = 0x1107c4u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | GPR_U64(ctx, 2));
    // 0x1107c8: 0x1645824  and         $t3, $t3, $a0
    ctx->pc = 0x1107c8u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & GPR_U64(ctx, 4));
    // 0x1107cc: 0x1635825  or          $t3, $t3, $v1
    ctx->pc = 0x1107ccu;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | GPR_U64(ctx, 3));
label_1107d0:
    // 0x1107d0: 0xff2b0000  sd          $t3, 0x0($t9)
    ctx->pc = 0x1107d0u;
    WRITE64(ADD32(GPR_U32(ctx, 25), 0), GPR_U64(ctx, 11));
label_1107d4:
    // 0x1107d4: 0x12000016  beqz        $s0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1107D4u;
    {
        const bool branch_taken_0x1107d4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1107D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1107D4u;
            // 0x1107d8: 0xdfa30000  ld          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1107d4) {
            ctx->pc = 0x110830u;
            goto label_110830;
        }
    }
    ctx->pc = 0x1107DCu;
    // 0x1107dc: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1107dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1107e0: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1107e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1107e4: 0x304c024  and         $t8, $t8, $a0
    ctx->pc = 0x1107e4u;
    SET_GPR_U64(ctx, 24, GPR_U64(ctx, 24) & GPR_U64(ctx, 4));
    // 0x1107e8: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1107e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1107ec: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1107ecu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1107f0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1107f0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1107f4: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1107f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1107f8: 0x31823  negu        $v1, $v1
    ctx->pc = 0x1107f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
    // 0x1107fc: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1107fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x110800: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x110800u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x110804: 0x302c025  or          $t8, $t8, $v0
    ctx->pc = 0x110804u;
    SET_GPR_U64(ctx, 24, GPR_U64(ctx, 24) | GPR_U64(ctx, 2));
    // 0x110808: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x110808u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11080c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x11080cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x110810: 0x18203c  dsll32      $a0, $t8, 0
    ctx->pc = 0x110810u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 24) << (32 + 0));
    // 0x110814: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x110814u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x110818: 0x302c024  and         $t8, $t8, $v0
    ctx->pc = 0x110818u;
    SET_GPR_U64(ctx, 24, GPR_U64(ctx, 24) & GPR_U64(ctx, 2));
    // 0x11081c: 0x4202b  sltu        $a0, $zero, $a0
    ctx->pc = 0x11081cu;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x110820: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x110820u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x110824: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x110824u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x110828: 0x303c025  or          $t8, $t8, $v1
    ctx->pc = 0x110828u;
    SET_GPR_U64(ctx, 24, GPR_U64(ctx, 24) | GPR_U64(ctx, 3));
    // 0x11082c: 0xffb80000  sd          $t8, 0x0($sp)
    ctx->pc = 0x11082cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 24));
label_110830:
    // 0x110830: 0xdfa20000  ld          $v0, 0x0($sp)
    ctx->pc = 0x110830u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x110834: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x110834u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x110838: 0x3e00008  jr          $ra
    ctx->pc = 0x110838u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11083Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110838u;
            // 0x11083c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x110224u: goto label_110224;
            case 0x110278u: goto label_110278;
            case 0x1102C8u: goto label_1102c8;
            case 0x1102DCu: goto label_1102dc;
            case 0x110314u: goto label_110314;
            case 0x110320u: goto label_110320;
            case 0x110334u: goto label_110334;
            case 0x110348u: goto label_110348;
            case 0x110360u: goto label_110360;
            case 0x110374u: goto label_110374;
            case 0x1103A8u: goto label_1103a8;
            case 0x1103DCu: goto label_1103dc;
            case 0x110420u: goto label_110420;
            case 0x110424u: goto label_110424;
            case 0x110434u: goto label_110434;
            case 0x110478u: goto label_110478;
            case 0x110480u: goto label_110480;
            case 0x110490u: goto label_110490;
            case 0x1104D4u: goto label_1104d4;
            case 0x1104E4u: goto label_1104e4;
            case 0x110520u: goto label_110520;
            case 0x110558u: goto label_110558;
            case 0x110598u: goto label_110598;
            case 0x1105B8u: goto label_1105b8;
            case 0x1105CCu: goto label_1105cc;
            case 0x110608u: goto label_110608;
            case 0x110618u: goto label_110618;
            case 0x110650u: goto label_110650;
            case 0x11068Cu: goto label_11068c;
            case 0x1106D8u: goto label_1106d8;
            case 0x1106DCu: goto label_1106dc;
            case 0x1106E4u: goto label_1106e4;
            case 0x110734u: goto label_110734;
            case 0x110738u: goto label_110738;
            case 0x110770u: goto label_110770;
            case 0x110780u: goto label_110780;
            case 0x1107D0u: goto label_1107d0;
            case 0x1107D4u: goto label_1107d4;
            case 0x110830u: goto label_110830;
            default: break;
        }
        return;
    }
    ctx->pc = 0x110840u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
