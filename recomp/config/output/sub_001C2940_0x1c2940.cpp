#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C2940
// Address: 0x1c2940 - 0x1c2d00
void sub_001C2940_0x1c2940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C2940_0x1c2940");
#endif

    switch (ctx->pc) {
        case 0x1c2b78u: goto label_1c2b78;
        case 0x1c2b88u: goto label_1c2b88;
        case 0x1c2ba0u: goto label_1c2ba0;
        case 0x1c2bacu: goto label_1c2bac;
        case 0x1c2bc4u: goto label_1c2bc4;
        case 0x1c2bf8u: goto label_1c2bf8;
        case 0x1c2c1cu: goto label_1c2c1c;
        case 0x1c2c50u: goto label_1c2c50;
        case 0x1c2c68u: goto label_1c2c68;
        case 0x1c2c80u: goto label_1c2c80;
        case 0x1c2c98u: goto label_1c2c98;
        case 0x1c2cb0u: goto label_1c2cb0;
        case 0x1c2cc8u: goto label_1c2cc8;
        case 0x1c2ce0u: goto label_1c2ce0;
        default: break;
    }

    ctx->pc = 0x1c2940u;

    // 0x1c2940: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c2940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c2944: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2944u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2948: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c2948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c294c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c294cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c2950: 0x8c306f10  lw          $s0, 0x6F10($at)
    ctx->pc = 0x1c2950u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 28432)));
    // 0x1c2954: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2954u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2958: 0x8c224218  lw          $v0, 0x4218($at)
    ctx->pc = 0x1c2958u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16920)));
    // 0x1c295c: 0xa6020008  sh          $v0, 0x8($s0)
    ctx->pc = 0x1c295cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c2960: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c2960u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2964: 0x8c224210  lw          $v0, 0x4210($at)
    ctx->pc = 0x1c2964u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16912)));
    // 0x1c2968: 0xa602000a  sh          $v0, 0xA($s0)
    ctx->pc = 0x1c2968u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c296c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c296cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c2970: 0x9603000a  lhu         $v1, 0xA($s0)
    ctx->pc = 0x1c2970u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c2974: 0x8c224228  lw          $v0, 0x4228($at)
    ctx->pc = 0x1c2974u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16936)));
    // 0x1c2978: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1c2978u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1c297c: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x1c297cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c2980: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1c2980u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1c2984: 0x2c41000a  sltiu       $at, $v0, 0xA
    ctx->pc = 0x1c2984u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1c2988: 0x102000d3  beqz        $at, . + 4 + (0xD3 << 2)
    ctx->pc = 0x1C2988u;
    {
        const bool branch_taken_0x1c2988 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C298Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2988u;
            // 0x1c298c: 0x3c030025  lui         $v1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2988) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2990u;
    // 0x1c2990: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1c2990u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1c2994: 0x24632cb0  addiu       $v1, $v1, 0x2CB0
    ctx->pc = 0x1c2994u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 11440));
    // 0x1c2998: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c2998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c299c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c299cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c29a0: 0x400008  jr          $v0
    ctx->pc = 0x1C29A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C29A8u: goto label_1c29a8;
            case 0x1C2B80u: goto label_1c2b80;
            case 0x1C2B98u: goto label_1c2b98;
            case 0x1C2BF0u: goto label_1c2bf0;
            case 0x1C2C48u: goto label_1c2c48;
            case 0x1C2C60u: goto label_1c2c60;
            case 0x1C2C78u: goto label_1c2c78;
            case 0x1C2C90u: goto label_1c2c90;
            case 0x1C2CA8u: goto label_1c2ca8;
            case 0x1C2CC0u: goto label_1c2cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C29A8u;
label_1c29a8:
    // 0x1c29a8: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x1c29a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1c29ac: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1c29acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c29b0: 0x10460055  beq         $v0, $a2, . + 4 + (0x55 << 2)
    ctx->pc = 0x1C29B0u;
    {
        const bool branch_taken_0x1c29b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 6));
        ctx->pc = 0x1C29B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C29B0u;
            // 0x1c29b4: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c29b0) {
            ctx->pc = 0x1C2B08u;
            goto label_1c2b08;
        }
    }
    ctx->pc = 0x1C29B8u;
    // 0x1c29b8: 0x1045003b  beq         $v0, $a1, . + 4 + (0x3B << 2)
    ctx->pc = 0x1C29B8u;
    {
        const bool branch_taken_0x1c29b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x1C29BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C29B8u;
            // 0x1c29bc: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c29b8) {
            ctx->pc = 0x1C2AA8u;
            goto label_1c2aa8;
        }
    }
    ctx->pc = 0x1C29C0u;
    // 0x1c29c0: 0x10440027  beq         $v0, $a0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1C29C0u;
    {
        const bool branch_taken_0x1c29c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C29C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C29C0u;
            // 0x1c29c4: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c29c0) {
            ctx->pc = 0x1C2A60u;
            goto label_1c2a60;
        }
    }
    ctx->pc = 0x1C29C8u;
    // 0x1c29c8: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C29C8u;
    {
        const bool branch_taken_0x1c29c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c29c8) {
            ctx->pc = 0x1C2A04u;
            goto label_1c2a04;
        }
    }
    ctx->pc = 0x1C29D0u;
    // 0x1c29d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C29D0u;
    {
        const bool branch_taken_0x1c29d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c29d0) {
            ctx->pc = 0x1C29E0u;
            goto label_1c29e0;
        }
    }
    ctx->pc = 0x1C29D8u;
    // 0x1c29d8: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1C29D8u;
    {
        const bool branch_taken_0x1c29d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C29DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C29D8u;
            // 0x1c29dc: 0xae000010  sw          $zero, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c29d8) {
            ctx->pc = 0x1C2B5Cu;
            goto label_1c2b5c;
        }
    }
    ctx->pc = 0x1C29E0u;
label_1c29e0:
    // 0x1c29e0: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1c29e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c29e4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C29E4u;
    {
        const bool branch_taken_0x1c29e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c29e4) {
            ctx->pc = 0x1C29F4u;
            goto label_1c29f4;
        }
    }
    ctx->pc = 0x1C29ECu;
    // 0x1c29ec: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C29ECu;
    {
        const bool branch_taken_0x1c29ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C29F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C29ECu;
            // 0x1c29f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c29ec) {
            ctx->pc = 0x1C29FCu;
            goto label_1c29fc;
        }
    }
    ctx->pc = 0x1C29F4u;
label_1c29f4:
    // 0x1c29f4: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1C29F4u;
    {
        const bool branch_taken_0x1c29f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C29F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C29F4u;
            // 0x1c29f8: 0xa2030001  sb          $v1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c29f4) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C29FCu;
label_1c29fc:
    // 0x1c29fc: 0x100000ba  b           . + 4 + (0xBA << 2)
    ctx->pc = 0x1C29FCu;
    {
        const bool branch_taken_0x1c29fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C29FCu;
            // 0x1c2a00: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c29fc) {
            ctx->pc = 0x1C2CE8u;
            goto label_1c2ce8;
        }
    }
    ctx->pc = 0x1C2A04u;
label_1c2a04:
    // 0x1c2a04: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1c2a04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c2a08: 0x10450010  beq         $v0, $a1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1C2A08u;
    {
        const bool branch_taken_0x1c2a08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        if (branch_taken_0x1c2a08) {
            ctx->pc = 0x1C2A4Cu;
            goto label_1c2a4c;
        }
    }
    ctx->pc = 0x1C2A10u;
    // 0x1c2a10: 0x1044000c  beq         $v0, $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x1C2A10u;
    {
        const bool branch_taken_0x1c2a10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c2a10) {
            ctx->pc = 0x1C2A44u;
            goto label_1c2a44;
        }
    }
    ctx->pc = 0x1C2A18u;
    // 0x1c2a18: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2A18u;
    {
        const bool branch_taken_0x1c2a18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C2A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A18u;
            // 0x1c2a1c: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a18) {
            ctx->pc = 0x1C2A28u;
            goto label_1c2a28;
        }
    }
    ctx->pc = 0x1C2A20u;
    // 0x1c2a20: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1C2A20u;
    {
        const bool branch_taken_0x1c2a20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A20u;
            // 0x1c2a24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a20) {
            ctx->pc = 0x1C2A58u;
            goto label_1c2a58;
        }
    }
    ctx->pc = 0x1C2A28u;
label_1c2a28:
    // 0x1c2a28: 0x90224476  lbu         $v0, 0x4476($at)
    ctx->pc = 0x1c2a28u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c2a2c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2A2Cu;
    {
        const bool branch_taken_0x1c2a2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2a2c) {
            ctx->pc = 0x1C2A3Cu;
            goto label_1c2a3c;
        }
    }
    ctx->pc = 0x1C2A34u;
    // 0x1c2a34: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1C2A34u;
    {
        const bool branch_taken_0x1c2a34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A34u;
            // 0x1c2a38: 0xa2040001  sb          $a0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a34) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2A3Cu;
label_1c2a3c:
    // 0x1c2a3c: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1C2A3Cu;
    {
        const bool branch_taken_0x1c2a3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A3Cu;
            // 0x1c2a40: 0xa2060001  sb          $a2, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a3c) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2A44u;
label_1c2a44:
    // 0x1c2a44: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1C2A44u;
    {
        const bool branch_taken_0x1c2a44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A44u;
            // 0x1c2a48: 0xa2050001  sb          $a1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a44) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2A4Cu;
label_1c2a4c:
    // 0x1c2a4c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c2a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2a50: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1C2A50u;
    {
        const bool branch_taken_0x1c2a50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A50u;
            // 0x1c2a54: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a50) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2A58u;
label_1c2a58:
    // 0x1c2a58: 0x100000a2  b           . + 4 + (0xA2 << 2)
    ctx->pc = 0x1C2A58u;
    {
        const bool branch_taken_0x1c2a58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2a58) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2A60u;
label_1c2a60:
    // 0x1c2a60: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x1c2a60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c2a64: 0x1064000c  beq         $v1, $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x1C2A64u;
    {
        const bool branch_taken_0x1c2a64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C2A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A64u;
            // 0x1c2a68: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a64) {
            ctx->pc = 0x1C2A98u;
            goto label_1c2a98;
        }
    }
    ctx->pc = 0x1C2A6Cu;
    // 0x1c2a6c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2A6Cu;
    {
        const bool branch_taken_0x1c2a6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C2A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A6Cu;
            // 0x1c2a70: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a6c) {
            ctx->pc = 0x1C2A7Cu;
            goto label_1c2a7c;
        }
    }
    ctx->pc = 0x1C2A74u;
    // 0x1c2a74: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C2A74u;
    {
        const bool branch_taken_0x1c2a74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A74u;
            // 0x1c2a78: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a74) {
            ctx->pc = 0x1C2AA0u;
            goto label_1c2aa0;
        }
    }
    ctx->pc = 0x1C2A7Cu;
label_1c2a7c:
    // 0x1c2a7c: 0x90224476  lbu         $v0, 0x4476($at)
    ctx->pc = 0x1c2a7cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c2a80: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2A80u;
    {
        const bool branch_taken_0x1c2a80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2a80) {
            ctx->pc = 0x1C2A90u;
            goto label_1c2a90;
        }
    }
    ctx->pc = 0x1C2A88u;
    // 0x1c2a88: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1C2A88u;
    {
        const bool branch_taken_0x1c2a88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A88u;
            // 0x1c2a8c: 0xa2040001  sb          $a0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a88) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2A90u;
label_1c2a90:
    // 0x1c2a90: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1C2A90u;
    {
        const bool branch_taken_0x1c2a90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A90u;
            // 0x1c2a94: 0xa2060001  sb          $a2, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a90) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2A98u;
label_1c2a98:
    // 0x1c2a98: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1C2A98u;
    {
        const bool branch_taken_0x1c2a98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2A98u;
            // 0x1c2a9c: 0xa2050001  sb          $a1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2a98) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2AA0u;
label_1c2aa0:
    // 0x1c2aa0: 0x10000090  b           . + 4 + (0x90 << 2)
    ctx->pc = 0x1C2AA0u;
    {
        const bool branch_taken_0x1c2aa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2aa0) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2AA8u;
label_1c2aa8:
    // 0x1c2aa8: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x1c2aa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c2aac: 0x10860012  beq         $a0, $a2, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C2AACu;
    {
        const bool branch_taken_0x1c2aac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 6));
        ctx->pc = 0x1C2AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2AACu;
            // 0x1c2ab0: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2aac) {
            ctx->pc = 0x1C2AF8u;
            goto label_1c2af8;
        }
    }
    ctx->pc = 0x1C2AB4u;
    // 0x1c2ab4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c2ab4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c2ab8: 0x1083000d  beq         $a0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1C2AB8u;
    {
        const bool branch_taken_0x1c2ab8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C2ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2AB8u;
            // 0x1c2abc: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ab8) {
            ctx->pc = 0x1C2AF0u;
            goto label_1c2af0;
        }
    }
    ctx->pc = 0x1C2AC0u;
    // 0x1c2ac0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2ac4: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2AC4u;
    {
        const bool branch_taken_0x1c2ac4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C2AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2AC4u;
            // 0x1c2ac8: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ac4) {
            ctx->pc = 0x1C2AD4u;
            goto label_1c2ad4;
        }
    }
    ctx->pc = 0x1C2ACCu;
    // 0x1c2acc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1C2ACCu;
    {
        const bool branch_taken_0x1c2acc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2AD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2ACCu;
            // 0x1c2ad0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2acc) {
            ctx->pc = 0x1C2B00u;
            goto label_1c2b00;
        }
    }
    ctx->pc = 0x1C2AD4u;
label_1c2ad4:
    // 0x1c2ad4: 0x90224476  lbu         $v0, 0x4476($at)
    ctx->pc = 0x1c2ad4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c2ad8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2AD8u;
    {
        const bool branch_taken_0x1c2ad8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2ad8) {
            ctx->pc = 0x1C2AE8u;
            goto label_1c2ae8;
        }
    }
    ctx->pc = 0x1C2AE0u;
    // 0x1c2ae0: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1C2AE0u;
    {
        const bool branch_taken_0x1c2ae0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2AE0u;
            // 0x1c2ae4: 0xa2030001  sb          $v1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ae0) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2AE8u;
label_1c2ae8:
    // 0x1c2ae8: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1C2AE8u;
    {
        const bool branch_taken_0x1c2ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2AE8u;
            // 0x1c2aec: 0xa2060001  sb          $a2, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ae8) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2AF0u;
label_1c2af0:
    // 0x1c2af0: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1C2AF0u;
    {
        const bool branch_taken_0x1c2af0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2AF0u;
            // 0x1c2af4: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2af0) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2AF8u;
label_1c2af8:
    // 0x1c2af8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1C2AF8u;
    {
        const bool branch_taken_0x1c2af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2AF8u;
            // 0x1c2afc: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2af8) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2B00u;
label_1c2b00:
    // 0x1c2b00: 0x10000078  b           . + 4 + (0x78 << 2)
    ctx->pc = 0x1C2B00u;
    {
        const bool branch_taken_0x1c2b00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2b00) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2B08u;
label_1c2b08:
    // 0x1c2b08: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x1c2b08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c2b0c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c2b0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c2b10: 0x1083000d  beq         $a0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1C2B10u;
    {
        const bool branch_taken_0x1c2b10 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C2B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B10u;
            // 0x1c2b14: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2b10) {
            ctx->pc = 0x1C2B48u;
            goto label_1c2b48;
        }
    }
    ctx->pc = 0x1C2B18u;
    // 0x1c2b18: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2b18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2b1c: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2B1Cu;
    {
        const bool branch_taken_0x1c2b1c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C2B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B1Cu;
            // 0x1c2b20: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2b1c) {
            ctx->pc = 0x1C2B2Cu;
            goto label_1c2b2c;
        }
    }
    ctx->pc = 0x1C2B24u;
    // 0x1c2b24: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C2B24u;
    {
        const bool branch_taken_0x1c2b24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B24u;
            // 0x1c2b28: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2b24) {
            ctx->pc = 0x1C2B50u;
            goto label_1c2b50;
        }
    }
    ctx->pc = 0x1C2B2Cu;
label_1c2b2c:
    // 0x1c2b2c: 0x90224476  lbu         $v0, 0x4476($at)
    ctx->pc = 0x1c2b2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c2b30: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2B30u;
    {
        const bool branch_taken_0x1c2b30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2b30) {
            ctx->pc = 0x1C2B40u;
            goto label_1c2b40;
        }
    }
    ctx->pc = 0x1C2B38u;
    // 0x1c2b38: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C2B38u;
    {
        const bool branch_taken_0x1c2b38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B38u;
            // 0x1c2b3c: 0xa2030001  sb          $v1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2b38) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2B40u;
label_1c2b40:
    // 0x1c2b40: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C2B40u;
    {
        const bool branch_taken_0x1c2b40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B40u;
            // 0x1c2b44: 0xa2060001  sb          $a2, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2b40) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2B48u;
label_1c2b48:
    // 0x1c2b48: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2B48u;
    {
        const bool branch_taken_0x1c2b48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B48u;
            // 0x1c2b4c: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2b48) {
            ctx->pc = 0x1C2B58u;
            goto label_1c2b58;
        }
    }
    ctx->pc = 0x1C2B50u;
label_1c2b50:
    // 0x1c2b50: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x1C2B50u;
    {
        const bool branch_taken_0x1c2b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2b50) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2B58u;
label_1c2b58:
    // 0x1c2b58: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x1c2b58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
label_1c2b5c:
    // 0x1c2b5c: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1c2b5cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1c2b60: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x1c2b60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x1c2b64: 0x24c62ca0  addiu       $a2, $a2, 0x2CA0
    ctx->pc = 0x1c2b64u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 11424));
    // 0x1c2b68: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x1c2b68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x1c2b6c: 0x8e0500f0  lw          $a1, 0xF0($s0)
    ctx->pc = 0x1c2b6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x1c2b70: 0xc071630  jal         func_1C58C0
    ctx->pc = 0x1C2B70u;
    SET_GPR_U32(ctx, 31, 0x1C2B78u);
    ctx->pc = 0x1C2B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B70u;
            // 0x1c2b74: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C58C0u;
    if (runtime->hasFunction(0x1C58C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C58C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2B78u; }
        if (ctx->pc != 0x1C2B78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C58C0_0x1c58c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2B78u; }
        if (ctx->pc != 0x1C2B78u) { return; }
    }
    ctx->pc = 0x1C2B78u;
label_1c2b78:
    // 0x1c2b78: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1C2B78u;
    {
        const bool branch_taken_0x1c2b78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2b78) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2B80u;
label_1c2b80:
    // 0x1c2b80: 0xc070b40  jal         func_1C2D00
    ctx->pc = 0x1C2B80u;
    SET_GPR_U32(ctx, 31, 0x1C2B88u);
    ctx->pc = 0x1C2B84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B80u;
            // 0x1c2b84: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2D00u;
    if (runtime->hasFunction(0x1C2D00u)) {
        auto targetFn = runtime->lookupFunction(0x1C2D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2B88u; }
        if (ctx->pc != 0x1C2B88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2D00_0x1c2d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2B88u; }
        if (ctx->pc != 0x1C2B88u) { return; }
    }
    ctx->pc = 0x1C2B88u;
label_1c2b88:
    // 0x1c2b88: 0x14400053  bnez        $v0, . + 4 + (0x53 << 2)
    ctx->pc = 0x1C2B88u;
    {
        const bool branch_taken_0x1c2b88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2b88) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2B90u;
    // 0x1c2b90: 0x10000054  b           . + 4 + (0x54 << 2)
    ctx->pc = 0x1C2B90u;
    {
        const bool branch_taken_0x1c2b90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2B94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B90u;
            // 0x1c2b94: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2b90) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2B98u;
label_1c2b98:
    // 0x1c2b98: 0xc070f24  jal         func_1C3C90
    ctx->pc = 0x1C2B98u;
    SET_GPR_U32(ctx, 31, 0x1C2BA0u);
    ctx->pc = 0x1C2B9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2B98u;
            // 0x1c2b9c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C3C90u;
    if (runtime->hasFunction(0x1C3C90u)) {
        auto targetFn = runtime->lookupFunction(0x1C3C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2BA0u; }
        if (ctx->pc != 0x1C2BA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C3C90_0x1c3c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2BA0u; }
        if (ctx->pc != 0x1C2BA0u) { return; }
    }
    ctx->pc = 0x1C2BA0u;
label_1c2ba0:
    // 0x1c2ba0: 0x1440004d  bnez        $v0, . + 4 + (0x4D << 2)
    ctx->pc = 0x1C2BA0u;
    {
        const bool branch_taken_0x1c2ba0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2ba0) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2BA8u;
    // 0x1c2ba8: 0x8e0200dc  lw          $v0, 0xDC($s0)
    ctx->pc = 0x1c2ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 220)));
label_1c2bac:
    // 0x1c2bac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2BACu;
    {
        const bool branch_taken_0x1c2bac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C2BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2BACu;
            // 0x1c2bb0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2bac) {
            ctx->pc = 0x1C2BBCu;
            goto label_1c2bbc;
        }
    }
    ctx->pc = 0x1C2BB4u;
    // 0x1c2bb4: 0x1000004b  b           . + 4 + (0x4B << 2)
    ctx->pc = 0x1C2BB4u;
    {
        const bool branch_taken_0x1c2bb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2bb4) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2BBCu;
label_1c2bbc:
    // 0x1c2bbc: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C2BBCu;
    SET_GPR_U32(ctx, 31, 0x1C2BC4u);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2BC4u; }
        if (ctx->pc != 0x1C2BC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2BC4u; }
        if (ctx->pc != 0x1C2BC4u) { return; }
    }
    ctx->pc = 0x1C2BC4u;
label_1c2bc4:
    // 0x1c2bc4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C2BC4u;
    {
        const bool branch_taken_0x1c2bc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2bc4) {
            ctx->pc = 0x1C2BE0u;
            goto label_1c2be0;
        }
    }
    ctx->pc = 0x1C2BCCu;
    // 0x1c2bcc: 0x8e0200e0  lw          $v0, 0xE0($s0)
    ctx->pc = 0x1c2bccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 224)));
    // 0x1c2bd0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C2BD0u;
    {
        const bool branch_taken_0x1c2bd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C2BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2BD0u;
            // 0x1c2bd4: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2bd0) {
            ctx->pc = 0x1C2BE4u;
            goto label_1c2be4;
        }
    }
    ctx->pc = 0x1C2BD8u;
    // 0x1c2bd8: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x1C2BD8u;
    {
        const bool branch_taken_0x1c2bd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2BD8u;
            // 0x1c2bdc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2bd8) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2BE0u;
label_1c2be0:
    // 0x1c2be0: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1c2be0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_1c2be4:
    // 0x1c2be4: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1c2be4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c2be8: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1C2BE8u;
    {
        const bool branch_taken_0x1c2be8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2BE8u;
            // 0x1c2bec: 0xa2000002  sb          $zero, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2be8) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2BF0u;
label_1c2bf0:
    // 0x1c2bf0: 0xc070c54  jal         func_1C3150
    ctx->pc = 0x1C2BF0u;
    SET_GPR_U32(ctx, 31, 0x1C2BF8u);
    ctx->pc = 0x1C2BF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2BF0u;
            // 0x1c2bf4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C3150u;
    if (runtime->hasFunction(0x1C3150u)) {
        auto targetFn = runtime->lookupFunction(0x1C3150u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2BF8u; }
        if (ctx->pc != 0x1C2BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C3150_0x1c3150(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2BF8u; }
        if (ctx->pc != 0x1C2BF8u) { return; }
    }
    ctx->pc = 0x1C2BF8u;
label_1c2bf8:
    // 0x1c2bf8: 0x14400037  bnez        $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x1C2BF8u;
    {
        const bool branch_taken_0x1c2bf8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2bf8) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2C00u;
    // 0x1c2c00: 0x8e0200dc  lw          $v0, 0xDC($s0)
    ctx->pc = 0x1c2c00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 220)));
    // 0x1c2c04: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2C04u;
    {
        const bool branch_taken_0x1c2c04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C2C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C04u;
            // 0x1c2c08: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2c04) {
            ctx->pc = 0x1C2C14u;
            goto label_1c2c14;
        }
    }
    ctx->pc = 0x1C2C0Cu;
    // 0x1c2c0c: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1C2C0Cu;
    {
        const bool branch_taken_0x1c2c0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2c0c) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2C14u;
label_1c2c14:
    // 0x1c2c14: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C2C14u;
    SET_GPR_U32(ctx, 31, 0x1C2C1Cu);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C1Cu; }
        if (ctx->pc != 0x1C2C1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C1Cu; }
        if (ctx->pc != 0x1C2C1Cu) { return; }
    }
    ctx->pc = 0x1C2C1Cu;
label_1c2c1c:
    // 0x1c2c1c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C2C1Cu;
    {
        const bool branch_taken_0x1c2c1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2c1c) {
            ctx->pc = 0x1C2C38u;
            goto label_1c2c38;
        }
    }
    ctx->pc = 0x1C2C24u;
    // 0x1c2c24: 0x8e0200e0  lw          $v0, 0xE0($s0)
    ctx->pc = 0x1c2c24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 224)));
    // 0x1c2c28: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C2C28u;
    {
        const bool branch_taken_0x1c2c28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C2C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C28u;
            // 0x1c2c2c: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2c28) {
            ctx->pc = 0x1C2C3Cu;
            goto label_1c2c3c;
        }
    }
    ctx->pc = 0x1C2C30u;
    // 0x1c2c30: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1C2C30u;
    {
        const bool branch_taken_0x1c2c30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C30u;
            // 0x1c2c34: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2c30) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2C38u;
label_1c2c38:
    // 0x1c2c38: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1c2c38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
label_1c2c3c:
    // 0x1c2c3c: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1c2c3cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c2c40: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1C2C40u;
    {
        const bool branch_taken_0x1c2c40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C40u;
            // 0x1c2c44: 0xa2000002  sb          $zero, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2c40) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2C48u;
label_1c2c48:
    // 0x1c2c48: 0xc07125c  jal         func_1C4970
    ctx->pc = 0x1C2C48u;
    SET_GPR_U32(ctx, 31, 0x1C2C50u);
    ctx->pc = 0x1C2C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C48u;
            // 0x1c2c4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C4970u;
    if (runtime->hasFunction(0x1C4970u)) {
        auto targetFn = runtime->lookupFunction(0x1C4970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C50u; }
        if (ctx->pc != 0x1C2C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4970_0x1c4970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C50u; }
        if (ctx->pc != 0x1C2C50u) { return; }
    }
    ctx->pc = 0x1C2C50u;
label_1c2c50:
    // 0x1c2c50: 0x14400021  bnez        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x1C2C50u;
    {
        const bool branch_taken_0x1c2c50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2c50) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2C58u;
    // 0x1c2c58: 0x1000ffd4  b           . + 4 + (-0x2C << 2)
    ctx->pc = 0x1C2C58u;
    {
        const bool branch_taken_0x1c2c58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C58u;
            // 0x1c2c5c: 0x8e0200dc  lw          $v0, 0xDC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 220)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2c58) {
            ctx->pc = 0x1C2BACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c2bac;
        }
    }
    ctx->pc = 0x1C2C60u;
label_1c2c60:
    // 0x1c2c60: 0xc0710e4  jal         func_1C4390
    ctx->pc = 0x1C2C60u;
    SET_GPR_U32(ctx, 31, 0x1C2C68u);
    ctx->pc = 0x1C2C64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C60u;
            // 0x1c2c64: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C4390u;
    if (runtime->hasFunction(0x1C4390u)) {
        auto targetFn = runtime->lookupFunction(0x1C4390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C68u; }
        if (ctx->pc != 0x1C2C68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4390_0x1c4390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C68u; }
        if (ctx->pc != 0x1C2C68u) { return; }
    }
    ctx->pc = 0x1C2C68u;
label_1c2c68:
    // 0x1c2c68: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1C2C68u;
    {
        const bool branch_taken_0x1c2c68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2c68) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2C70u;
    // 0x1c2c70: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1C2C70u;
    {
        const bool branch_taken_0x1c2c70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C70u;
            // 0x1c2c74: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2c70) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2C78u;
label_1c2c78:
    // 0x1c2c78: 0xc070e54  jal         func_1C3950
    ctx->pc = 0x1C2C78u;
    SET_GPR_U32(ctx, 31, 0x1C2C80u);
    ctx->pc = 0x1C2C7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C78u;
            // 0x1c2c7c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C3950u;
    if (runtime->hasFunction(0x1C3950u)) {
        auto targetFn = runtime->lookupFunction(0x1C3950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C80u; }
        if (ctx->pc != 0x1C2C80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C3950_0x1c3950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C80u; }
        if (ctx->pc != 0x1C2C80u) { return; }
    }
    ctx->pc = 0x1C2C80u;
label_1c2c80:
    // 0x1c2c80: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1C2C80u;
    {
        const bool branch_taken_0x1c2c80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2c80) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2C88u;
    // 0x1c2c88: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1C2C88u;
    {
        const bool branch_taken_0x1c2c88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C88u;
            // 0x1c2c8c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2c88) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2C90u;
label_1c2c90:
    // 0x1c2c90: 0xc070d64  jal         func_1C3590
    ctx->pc = 0x1C2C90u;
    SET_GPR_U32(ctx, 31, 0x1C2C98u);
    ctx->pc = 0x1C2C94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2C90u;
            // 0x1c2c94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C3590u;
    if (runtime->hasFunction(0x1C3590u)) {
        auto targetFn = runtime->lookupFunction(0x1C3590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C98u; }
        if (ctx->pc != 0x1C2C98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C3590_0x1c3590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2C98u; }
        if (ctx->pc != 0x1C2C98u) { return; }
    }
    ctx->pc = 0x1C2C98u;
label_1c2c98:
    // 0x1c2c98: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1C2C98u;
    {
        const bool branch_taken_0x1c2c98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2c98) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2CA0u;
    // 0x1c2ca0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1C2CA0u;
    {
        const bool branch_taken_0x1c2ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2CA0u;
            // 0x1c2ca4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ca0) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2CA8u;
label_1c2ca8:
    // 0x1c2ca8: 0xc071328  jal         func_1C4CA0
    ctx->pc = 0x1C2CA8u;
    SET_GPR_U32(ctx, 31, 0x1C2CB0u);
    ctx->pc = 0x1C2CACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2CA8u;
            // 0x1c2cac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C4CA0u;
    if (runtime->hasFunction(0x1C4CA0u)) {
        auto targetFn = runtime->lookupFunction(0x1C4CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2CB0u; }
        if (ctx->pc != 0x1C2CB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4CA0_0x1c4ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2CB0u; }
        if (ctx->pc != 0x1C2CB0u) { return; }
    }
    ctx->pc = 0x1C2CB0u;
label_1c2cb0:
    // 0x1c2cb0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C2CB0u;
    {
        const bool branch_taken_0x1c2cb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2cb0) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2CB8u;
    // 0x1c2cb8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C2CB8u;
    {
        const bool branch_taken_0x1c2cb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2CB8u;
            // 0x1c2cbc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2cb8) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2CC0u;
label_1c2cc0:
    // 0x1c2cc0: 0xc071378  jal         func_1C4DE0
    ctx->pc = 0x1C2CC0u;
    SET_GPR_U32(ctx, 31, 0x1C2CC8u);
    ctx->pc = 0x1C2CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2CC0u;
            // 0x1c2cc4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C4DE0u;
    if (runtime->hasFunction(0x1C4DE0u)) {
        auto targetFn = runtime->lookupFunction(0x1C4DE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2CC8u; }
        if (ctx->pc != 0x1C2CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4DE0_0x1c4de0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2CC8u; }
        if (ctx->pc != 0x1C2CC8u) { return; }
    }
    ctx->pc = 0x1C2CC8u;
label_1c2cc8:
    // 0x1c2cc8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2CC8u;
    {
        const bool branch_taken_0x1c2cc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c2cc8) {
            ctx->pc = 0x1C2CD8u;
            goto label_1c2cd8;
        }
    }
    ctx->pc = 0x1C2CD0u;
    // 0x1c2cd0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C2CD0u;
    {
        const bool branch_taken_0x1c2cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2CD0u;
            // 0x1c2cd4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2cd0) {
            ctx->pc = 0x1C2CE4u;
            goto label_1c2ce4;
        }
    }
    ctx->pc = 0x1C2CD8u;
label_1c2cd8:
    // 0x1c2cd8: 0xc0700e8  jal         func_1C03A0
    ctx->pc = 0x1C2CD8u;
    SET_GPR_U32(ctx, 31, 0x1C2CE0u);
    ctx->pc = 0x1C03A0u;
    if (runtime->hasFunction(0x1C03A0u)) {
        auto targetFn = runtime->lookupFunction(0x1C03A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2CE0u; }
        if (ctx->pc != 0x1C2CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C03A0_0x1c03a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2CE0u; }
        if (ctx->pc != 0x1C2CE0u) { return; }
    }
    ctx->pc = 0x1C2CE0u;
label_1c2ce0:
    // 0x1c2ce0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c2ce4:
    // 0x1c2ce4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c2ce4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1c2ce8:
    // 0x1c2ce8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c2ce8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c2cec: 0x3e00008  jr          $ra
    ctx->pc = 0x1C2CECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C2CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2CECu;
            // 0x1c2cf0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C29A8u: goto label_1c29a8;
            case 0x1C29E0u: goto label_1c29e0;
            case 0x1C29F4u: goto label_1c29f4;
            case 0x1C29FCu: goto label_1c29fc;
            case 0x1C2A04u: goto label_1c2a04;
            case 0x1C2A28u: goto label_1c2a28;
            case 0x1C2A3Cu: goto label_1c2a3c;
            case 0x1C2A44u: goto label_1c2a44;
            case 0x1C2A4Cu: goto label_1c2a4c;
            case 0x1C2A58u: goto label_1c2a58;
            case 0x1C2A60u: goto label_1c2a60;
            case 0x1C2A7Cu: goto label_1c2a7c;
            case 0x1C2A90u: goto label_1c2a90;
            case 0x1C2A98u: goto label_1c2a98;
            case 0x1C2AA0u: goto label_1c2aa0;
            case 0x1C2AA8u: goto label_1c2aa8;
            case 0x1C2AD4u: goto label_1c2ad4;
            case 0x1C2AE8u: goto label_1c2ae8;
            case 0x1C2AF0u: goto label_1c2af0;
            case 0x1C2AF8u: goto label_1c2af8;
            case 0x1C2B00u: goto label_1c2b00;
            case 0x1C2B08u: goto label_1c2b08;
            case 0x1C2B2Cu: goto label_1c2b2c;
            case 0x1C2B40u: goto label_1c2b40;
            case 0x1C2B48u: goto label_1c2b48;
            case 0x1C2B50u: goto label_1c2b50;
            case 0x1C2B58u: goto label_1c2b58;
            case 0x1C2B5Cu: goto label_1c2b5c;
            case 0x1C2B78u: goto label_1c2b78;
            case 0x1C2B80u: goto label_1c2b80;
            case 0x1C2B88u: goto label_1c2b88;
            case 0x1C2B98u: goto label_1c2b98;
            case 0x1C2BA0u: goto label_1c2ba0;
            case 0x1C2BACu: goto label_1c2bac;
            case 0x1C2BBCu: goto label_1c2bbc;
            case 0x1C2BC4u: goto label_1c2bc4;
            case 0x1C2BE0u: goto label_1c2be0;
            case 0x1C2BE4u: goto label_1c2be4;
            case 0x1C2BF0u: goto label_1c2bf0;
            case 0x1C2BF8u: goto label_1c2bf8;
            case 0x1C2C14u: goto label_1c2c14;
            case 0x1C2C1Cu: goto label_1c2c1c;
            case 0x1C2C38u: goto label_1c2c38;
            case 0x1C2C3Cu: goto label_1c2c3c;
            case 0x1C2C48u: goto label_1c2c48;
            case 0x1C2C50u: goto label_1c2c50;
            case 0x1C2C60u: goto label_1c2c60;
            case 0x1C2C68u: goto label_1c2c68;
            case 0x1C2C78u: goto label_1c2c78;
            case 0x1C2C80u: goto label_1c2c80;
            case 0x1C2C90u: goto label_1c2c90;
            case 0x1C2C98u: goto label_1c2c98;
            case 0x1C2CA8u: goto label_1c2ca8;
            case 0x1C2CB0u: goto label_1c2cb0;
            case 0x1C2CC0u: goto label_1c2cc0;
            case 0x1C2CC8u: goto label_1c2cc8;
            case 0x1C2CD8u: goto label_1c2cd8;
            case 0x1C2CE0u: goto label_1c2ce0;
            case 0x1C2CE4u: goto label_1c2ce4;
            case 0x1C2CE8u: goto label_1c2ce8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C2CF4u;
    // 0x1c2cf4: 0x0  nop
    ctx->pc = 0x1c2cf4u;
    // NOP
    // 0x1c2cf8: 0x0  nop
    ctx->pc = 0x1c2cf8u;
    // NOP
    // 0x1c2cfc: 0x0  nop
    ctx->pc = 0x1c2cfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
