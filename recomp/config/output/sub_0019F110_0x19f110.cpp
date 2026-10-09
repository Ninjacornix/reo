#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019F110
// Address: 0x19f110 - 0x19f380
void sub_0019F110_0x19f110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019F110_0x19f110");
#endif

    switch (ctx->pc) {
        case 0x19f154u: goto label_19f154;
        case 0x19f164u: goto label_19f164;
        case 0x19f18cu: goto label_19f18c;
        case 0x19f24cu: goto label_19f24c;
        case 0x19f270u: goto label_19f270;
        default: break;
    }

    ctx->pc = 0x19f110u;

    // 0x19f110: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x19f110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x19f114: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f114u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f118: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x19f118u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19f11c: 0xc02d  daddu       $t8, $zero, $zero
    ctx->pc = 0x19f11cu;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f120: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19f120u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19f124: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19f124u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19f128: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19f128u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19f12c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19f12cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19f130: 0x8c2dbed0  lw          $t5, -0x4130($at)
    ctx->pc = 0x19f130u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950608)));
    // 0x19f134: 0x3c09002a  lui         $t1, 0x2A
    ctx->pc = 0x19f134u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)42 << 16));
    // 0x19f138: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19f138u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19f13c: 0x240b0001  addiu       $t3, $zero, 0x1
    ctx->pc = 0x19f13cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f140: 0x25298680  addiu       $t1, $t1, -0x7980
    ctx->pc = 0x19f140u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294936192));
    // 0x19f144: 0x24e74e80  addiu       $a3, $a3, 0x4E80
    ctx->pc = 0x19f144u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 20096));
    // 0x19f148: 0x3c08ffff  lui         $t0, 0xFFFF
    ctx->pc = 0x19f148u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)65535 << 16));
    // 0x19f14c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x19f14cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19f150: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x19f150u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
label_19f154:
    // 0x19f154: 0x15a00003  bnez        $t5, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F154u;
    {
        const bool branch_taken_0x19f154 = (GPR_U64(ctx, 13) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F154u;
            // 0x19f158: 0x1a0102d  daddu       $v0, $t5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f154) {
            ctx->pc = 0x19F164u;
            goto label_19f164;
        }
    }
    ctx->pc = 0x19F15Cu;
    // 0x19f15c: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x19F15Cu;
    {
        const bool branch_taken_0x19f15c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F15Cu;
            // 0x19f160: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f15c) {
            ctx->pc = 0x19F360u;
            goto label_19f360;
        }
    }
    ctx->pc = 0x19F164u;
label_19f164:
    // 0x19f164: 0x17000007  bnez        $t8, . + 4 + (0x7 << 2)
    ctx->pc = 0x19F164u;
    {
        const bool branch_taken_0x19f164 = (GPR_U64(ctx, 24) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F164u;
            // 0x19f168: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f164) {
            ctx->pc = 0x19F184u;
            goto label_19f184;
        }
    }
    ctx->pc = 0x19F16Cu;
    // 0x19f16c: 0x8c4c0010  lw          $t4, 0x10($v0)
    ctx->pc = 0x19f16cu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x19f170: 0x118b0003  beq         $t4, $t3, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F170u;
    {
        const bool branch_taken_0x19f170 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 11));
        if (branch_taken_0x19f170) {
            ctx->pc = 0x19F180u;
            goto label_19f180;
        }
    }
    ctx->pc = 0x19F178u;
    // 0x19f178: 0x158a0067  bne         $t4, $t2, . + 4 + (0x67 << 2)
    ctx->pc = 0x19F178u;
    {
        const bool branch_taken_0x19f178 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 10));
        if (branch_taken_0x19f178) {
            ctx->pc = 0x19F318u;
            goto label_19f318;
        }
    }
    ctx->pc = 0x19F180u;
label_19f180:
    // 0x19f180: 0x602d  daddu       $t4, $zero, $zero
    ctx->pc = 0x19f180u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19f184:
    // 0x19f184: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x19F184u;
    {
        const bool branch_taken_0x19f184 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F184u;
            // 0x19f188: 0x186702a  slt         $t6, $t4, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 14, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f184) {
            ctx->pc = 0x19F1F0u;
            goto label_19f1f0;
        }
    }
    ctx->pc = 0x19F18Cu;
label_19f18c:
    // 0x19f18c: 0xae7021  addu        $t6, $a1, $t6
    ctx->pc = 0x19f18cu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 14)));
    // 0x19f190: 0x8dd10000  lw          $s1, 0x0($t6)
    ctx->pc = 0x19f190u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x19f194: 0x322effff  andi        $t6, $s1, 0xFFFF
    ctx->pc = 0x19f194u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x19f198: 0x11c00008  beqz        $t6, . + 4 + (0x8 << 2)
    ctx->pc = 0x19F198u;
    {
        const bool branch_taken_0x19f198 = (GPR_U64(ctx, 14) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F198u;
            // 0x19f19c: 0x25d0ffff  addiu       $s0, $t6, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 14), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f198) {
            ctx->pc = 0x19F1BCu;
            goto label_19f1bc;
        }
    }
    ctx->pc = 0x19F1A0u;
    // 0x19f1a0: 0x8c4e0008  lw          $t6, 0x8($v0)
    ctx->pc = 0x19f1a0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x19f1a4: 0x1078c0  sll         $t7, $s0, 3
    ctx->pc = 0x19f1a4u;
    SET_GPR_S32(ctx, 15, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x19f1a8: 0x1f07823  subu        $t7, $t7, $s0
    ctx->pc = 0x19f1a8u;
    SET_GPR_S32(ctx, 15, (int32_t)SUB32(GPR_U32(ctx, 15), GPR_U32(ctx, 16)));
    // 0x19f1ac: 0xf78c0  sll         $t7, $t7, 3
    ctx->pc = 0x19f1acu;
    SET_GPR_S32(ctx, 15, (int32_t)SLL32(GPR_U32(ctx, 15), 3));
    // 0x19f1b0: 0x12f7821  addu        $t7, $t1, $t7
    ctx->pc = 0x19f1b0u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 15)));
    // 0x19f1b4: 0x11ee0058  beq         $t7, $t6, . + 4 + (0x58 << 2)
    ctx->pc = 0x19F1B4u;
    {
        const bool branch_taken_0x19f1b4 = (GPR_U64(ctx, 15) == GPR_U64(ctx, 14));
        if (branch_taken_0x19f1b4) {
            ctx->pc = 0x19F318u;
            goto label_19f318;
        }
    }
    ctx->pc = 0x19F1BCu;
label_19f1bc:
    // 0x19f1bc: 0x2287024  and         $t6, $s1, $t0
    ctx->pc = 0x19f1bcu;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 17) & GPR_U64(ctx, 8));
    // 0x19f1c0: 0xe7402  srl         $t6, $t6, 16
    ctx->pc = 0x19f1c0u;
    SET_GPR_S32(ctx, 14, (int32_t)SRL32(GPR_U32(ctx, 14), 16));
    // 0x19f1c4: 0x11c00008  beqz        $t6, . + 4 + (0x8 << 2)
    ctx->pc = 0x19F1C4u;
    {
        const bool branch_taken_0x19f1c4 = (GPR_U64(ctx, 14) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F1C4u;
            // 0x19f1c8: 0x25d0ffff  addiu       $s0, $t6, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 14), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f1c4) {
            ctx->pc = 0x19F1E8u;
            goto label_19f1e8;
        }
    }
    ctx->pc = 0x19F1CCu;
    // 0x19f1cc: 0x8c4e0008  lw          $t6, 0x8($v0)
    ctx->pc = 0x19f1ccu;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x19f1d0: 0x1078c0  sll         $t7, $s0, 3
    ctx->pc = 0x19f1d0u;
    SET_GPR_S32(ctx, 15, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x19f1d4: 0x1f07823  subu        $t7, $t7, $s0
    ctx->pc = 0x19f1d4u;
    SET_GPR_S32(ctx, 15, (int32_t)SUB32(GPR_U32(ctx, 15), GPR_U32(ctx, 16)));
    // 0x19f1d8: 0xf78c0  sll         $t7, $t7, 3
    ctx->pc = 0x19f1d8u;
    SET_GPR_S32(ctx, 15, (int32_t)SLL32(GPR_U32(ctx, 15), 3));
    // 0x19f1dc: 0xef7821  addu        $t7, $a3, $t7
    ctx->pc = 0x19f1dcu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 15)));
    // 0x19f1e0: 0x11ee004d  beq         $t7, $t6, . + 4 + (0x4D << 2)
    ctx->pc = 0x19F1E0u;
    {
        const bool branch_taken_0x19f1e0 = (GPR_U64(ctx, 15) == GPR_U64(ctx, 14));
        if (branch_taken_0x19f1e0) {
            ctx->pc = 0x19F318u;
            goto label_19f318;
        }
    }
    ctx->pc = 0x19F1E8u;
label_19f1e8:
    // 0x19f1e8: 0x258c0001  addiu       $t4, $t4, 0x1
    ctx->pc = 0x19f1e8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
    // 0x19f1ec: 0x186702a  slt         $t6, $t4, $a2
    ctx->pc = 0x19f1ecu;
    SET_GPR_U64(ctx, 14, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
label_19f1f0:
    // 0x19f1f0: 0x15c0ffe6  bnez        $t6, . + 4 + (-0x1A << 2)
    ctx->pc = 0x19F1F0u;
    {
        const bool branch_taken_0x19f1f0 = (GPR_U64(ctx, 14) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F1F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F1F0u;
            // 0x19f1f4: 0xc7080  sll         $t6, $t4, 2 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)SLL32(GPR_U32(ctx, 12), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f1f0) {
            ctx->pc = 0x19F18Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f18c;
        }
    }
    ctx->pc = 0x19F1F8u;
    // 0x19f1f8: 0x848c0012  lh          $t4, 0x12($a0)
    ctx->pc = 0x19f1f8u;
    SET_GPR_S32(ctx, 12, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x19f1fc: 0x84500014  lh          $s0, 0x14($v0)
    ctx->pc = 0x19f1fcu;
    SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x19f200: 0x258cffff  addiu       $t4, $t4, -0x1
    ctx->pc = 0x19f200u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967295));
    // 0x19f204: 0x1807027  not         $t6, $t4
    ctx->pc = 0x19f204u;
    SET_GPR_U64(ctx, 14, ~(GPR_U64(ctx, 12) | GPR_U64(ctx, 0)));
    // 0x19f208: 0x20c6021  addu        $t4, $s0, $t4
    ctx->pc = 0x19f208u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 12)));
    // 0x19f20c: 0x1cc7824  and         $t7, $t6, $t4
    ctx->pc = 0x19f20cu;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 14) & GPR_U64(ctx, 12));
    // 0x19f210: 0x160f0042  bne         $s0, $t7, . + 4 + (0x42 << 2)
    ctx->pc = 0x19F210u;
    {
        const bool branch_taken_0x19f210 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 15));
        ctx->pc = 0x19F214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F210u;
            // 0x19f214: 0x40602d  daddu       $t4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f210) {
            ctx->pc = 0x19F31Cu;
            goto label_19f31c;
        }
    }
    ctx->pc = 0x19F218u;
    // 0x19f218: 0x8c500004  lw          $s0, 0x4($v0)
    ctx->pc = 0x19f218u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x19f21c: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x19F21Cu;
    {
        const bool branch_taken_0x19f21c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f21c) {
            ctx->pc = 0x19F240u;
            goto label_19f240;
        }
    }
    ctx->pc = 0x19F224u;
    // 0x19f224: 0x848c0010  lh          $t4, 0x10($a0)
    ctx->pc = 0x19f224u;
    SET_GPR_S32(ctx, 12, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x19f228: 0x6f7023  subu        $t6, $v1, $t7
    ctx->pc = 0x19f228u;
    SET_GPR_S32(ctx, 14, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 15)));
    // 0x19f22c: 0x1cc602b  sltu        $t4, $t6, $t4
    ctx->pc = 0x19f22cu;
    SET_GPR_U64(ctx, 12, ((uint64_t)GPR_U64(ctx, 14) < (uint64_t)GPR_U64(ctx, 12)) ? 1 : 0);
    // 0x19f230: 0x15800039  bnez        $t4, . + 4 + (0x39 << 2)
    ctx->pc = 0x19F230u;
    {
        const bool branch_taken_0x19f230 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f230) {
            ctx->pc = 0x19F318u;
            goto label_19f318;
        }
    }
    ctx->pc = 0x19F238u;
    // 0x19f238: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x19F238u;
    {
        const bool branch_taken_0x19f238 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F23Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F238u;
            // 0x19f23c: 0x7bb40040  lq          $s4, 0x40($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f238) {
            ctx->pc = 0x19F364u;
            goto label_19f364;
        }
    }
    ctx->pc = 0x19F240u;
label_19f240:
    // 0x19f240: 0x848e0010  lh          $t6, 0x10($a0)
    ctx->pc = 0x19f240u;
    SET_GPR_S32(ctx, 14, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x19f244: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x19F244u;
    {
        const bool branch_taken_0x19f244 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F244u;
            // 0x19f248: 0x40c82d  daddu       $t9, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f244) {
            ctx->pc = 0x19F2FCu;
            goto label_19f2fc;
        }
    }
    ctx->pc = 0x19F24Cu;
label_19f24c:
    // 0x19f24c: 0x17000006  bnez        $t8, . + 4 + (0x6 << 2)
    ctx->pc = 0x19F24Cu;
    {
        const bool branch_taken_0x19f24c = (GPR_U64(ctx, 24) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F24Cu;
            // 0x19f250: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f24c) {
            ctx->pc = 0x19F268u;
            goto label_19f268;
        }
    }
    ctx->pc = 0x19F254u;
    // 0x19f254: 0x8e0c0010  lw          $t4, 0x10($s0)
    ctx->pc = 0x19f254u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x19f258: 0x118b0003  beq         $t4, $t3, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F258u;
    {
        const bool branch_taken_0x19f258 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 11));
        if (branch_taken_0x19f258) {
            ctx->pc = 0x19F268u;
            goto label_19f268;
        }
    }
    ctx->pc = 0x19F260u;
    // 0x19f260: 0x158a002d  bne         $t4, $t2, . + 4 + (0x2D << 2)
    ctx->pc = 0x19F260u;
    {
        const bool branch_taken_0x19f260 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 10));
        if (branch_taken_0x19f260) {
            ctx->pc = 0x19F318u;
            goto label_19f318;
        }
    }
    ctx->pc = 0x19F268u;
label_19f268:
    // 0x19f268: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x19F268u;
    {
        const bool branch_taken_0x19f268 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F268u;
            // 0x19f26c: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f268) {
            ctx->pc = 0x19F2D0u;
            goto label_19f2d0;
        }
    }
    ctx->pc = 0x19F270u;
label_19f270:
    // 0x19f270: 0xb18821  addu        $s1, $a1, $s1
    ctx->pc = 0x19f270u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 17)));
    // 0x19f274: 0x8e340000  lw          $s4, 0x0($s1)
    ctx->pc = 0x19f274u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x19f278: 0x3291ffff  andi        $s1, $s4, 0xFFFF
    ctx->pc = 0x19f278u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)65535);
    // 0x19f27c: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x19F27Cu;
    {
        const bool branch_taken_0x19f27c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F27Cu;
            // 0x19f280: 0x2633ffff  addiu       $s3, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f27c) {
            ctx->pc = 0x19F2A0u;
            goto label_19f2a0;
        }
    }
    ctx->pc = 0x19F284u;
    // 0x19f284: 0x8e110008  lw          $s1, 0x8($s0)
    ctx->pc = 0x19f284u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x19f288: 0x1390c0  sll         $s2, $s3, 3
    ctx->pc = 0x19f288u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x19f28c: 0x2539023  subu        $s2, $s2, $s3
    ctx->pc = 0x19f28cu;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
    // 0x19f290: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x19f290u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x19f294: 0x1329021  addu        $s2, $t1, $s2
    ctx->pc = 0x19f294u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 18)));
    // 0x19f298: 0x1251001f  beq         $s2, $s1, . + 4 + (0x1F << 2)
    ctx->pc = 0x19F298u;
    {
        const bool branch_taken_0x19f298 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 17));
        if (branch_taken_0x19f298) {
            ctx->pc = 0x19F318u;
            goto label_19f318;
        }
    }
    ctx->pc = 0x19F2A0u;
label_19f2a0:
    // 0x19f2a0: 0x2888824  and         $s1, $s4, $t0
    ctx->pc = 0x19f2a0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 20) & GPR_U64(ctx, 8));
    // 0x19f2a4: 0x118c02  srl         $s1, $s1, 16
    ctx->pc = 0x19f2a4u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 17), 16));
    // 0x19f2a8: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x19F2A8u;
    {
        const bool branch_taken_0x19f2a8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F2ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F2A8u;
            // 0x19f2ac: 0x2633ffff  addiu       $s3, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f2a8) {
            ctx->pc = 0x19F2CCu;
            goto label_19f2cc;
        }
    }
    ctx->pc = 0x19F2B0u;
    // 0x19f2b0: 0x8e110008  lw          $s1, 0x8($s0)
    ctx->pc = 0x19f2b0u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x19f2b4: 0x1390c0  sll         $s2, $s3, 3
    ctx->pc = 0x19f2b4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x19f2b8: 0x2539023  subu        $s2, $s2, $s3
    ctx->pc = 0x19f2b8u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
    // 0x19f2bc: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x19f2bcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x19f2c0: 0xf29021  addu        $s2, $a3, $s2
    ctx->pc = 0x19f2c0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 18)));
    // 0x19f2c4: 0x12510014  beq         $s2, $s1, . + 4 + (0x14 << 2)
    ctx->pc = 0x19F2C4u;
    {
        const bool branch_taken_0x19f2c4 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 17));
        if (branch_taken_0x19f2c4) {
            ctx->pc = 0x19F318u;
            goto label_19f318;
        }
    }
    ctx->pc = 0x19F2CCu;
label_19f2cc:
    // 0x19f2cc: 0x258c0001  addiu       $t4, $t4, 0x1
    ctx->pc = 0x19f2ccu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
label_19f2d0:
    // 0x19f2d0: 0x186882a  slt         $s1, $t4, $a2
    ctx->pc = 0x19f2d0u;
    SET_GPR_U64(ctx, 17, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x19f2d4: 0x1620ffe6  bnez        $s1, . + 4 + (-0x1A << 2)
    ctx->pc = 0x19F2D4u;
    {
        const bool branch_taken_0x19f2d4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F2D4u;
            // 0x19f2d8: 0xc8880  sll         $s1, $t4, 2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 12), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f2d4) {
            ctx->pc = 0x19F270u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f270;
        }
    }
    ctx->pc = 0x19F2DCu;
    // 0x19f2dc: 0x8e100004  lw          $s0, 0x4($s0)
    ctx->pc = 0x19f2dcu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x19f2e0: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x19F2E0u;
    {
        const bool branch_taken_0x19f2e0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F2E0u;
            // 0x19f2e4: 0x6f6023  subu        $t4, $v1, $t7 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 15)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f2e0) {
            ctx->pc = 0x19F2FCu;
            goto label_19f2fc;
        }
    }
    ctx->pc = 0x19F2E8u;
    // 0x19f2e8: 0x18e602b  sltu        $t4, $t4, $t6
    ctx->pc = 0x19f2e8u;
    SET_GPR_U64(ctx, 12, ((uint64_t)GPR_U64(ctx, 12) < (uint64_t)GPR_U64(ctx, 14)) ? 1 : 0);
    // 0x19f2ec: 0x1580000a  bnez        $t4, . + 4 + (0xA << 2)
    ctx->pc = 0x19F2ECu;
    {
        const bool branch_taken_0x19f2ec = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f2ec) {
            ctx->pc = 0x19F318u;
            goto label_19f318;
        }
    }
    ctx->pc = 0x19F2F4u;
    // 0x19f2f4: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x19F2F4u;
    {
        const bool branch_taken_0x19f2f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F2F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F2F4u;
            // 0x19f2f8: 0x320102d  daddu       $v0, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f2f4) {
            ctx->pc = 0x19F360u;
            goto label_19f360;
        }
    }
    ctx->pc = 0x19F2FCu;
label_19f2fc:
    // 0x19f2fc: 0x86020014  lh          $v0, 0x14($s0)
    ctx->pc = 0x19f2fcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x19f300: 0x4f1023  subu        $v0, $v0, $t7
    ctx->pc = 0x19f300u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 15)));
    // 0x19f304: 0x4e102b  sltu        $v0, $v0, $t6
    ctx->pc = 0x19f304u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 14)) ? 1 : 0);
    // 0x19f308: 0x1440ffd0  bnez        $v0, . + 4 + (-0x30 << 2)
    ctx->pc = 0x19F308u;
    {
        const bool branch_taken_0x19f308 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F30Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F308u;
            // 0x19f30c: 0x320102d  daddu       $v0, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f308) {
            ctx->pc = 0x19F24Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f24c;
        }
    }
    ctx->pc = 0x19F310u;
    // 0x19f310: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x19F310u;
    {
        const bool branch_taken_0x19f310 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19f310) {
            ctx->pc = 0x19F360u;
            goto label_19f360;
        }
    }
    ctx->pc = 0x19F318u;
label_19f318:
    // 0x19f318: 0x40602d  daddu       $t4, $v0, $zero
    ctx->pc = 0x19f318u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_19f31c:
    // 0x19f31c: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x19f31cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x19f320: 0x1440ff90  bnez        $v0, . + 4 + (-0x70 << 2)
    ctx->pc = 0x19F320u;
    {
        const bool branch_taken_0x19f320 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f320) {
            ctx->pc = 0x19F164u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f164;
        }
    }
    ctx->pc = 0x19F328u;
    // 0x19f328: 0x858e0014  lh          $t6, 0x14($t4)
    ctx->pc = 0x19f328u;
    SET_GPR_S32(ctx, 14, (int16_t)READ16(ADD32(GPR_U32(ctx, 12), 20)));
    // 0x19f32c: 0x84820010  lh          $v0, 0x10($a0)
    ctx->pc = 0x19f32cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x19f330: 0x858c0016  lh          $t4, 0x16($t4)
    ctx->pc = 0x19f330u;
    SET_GPR_S32(ctx, 12, (int16_t)READ16(ADD32(GPR_U32(ctx, 12), 22)));
    // 0x19f334: 0x1cc6021  addu        $t4, $t6, $t4
    ctx->pc = 0x19f334u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 12)));
    // 0x19f338: 0x6c6023  subu        $t4, $v1, $t4
    ctx->pc = 0x19f338u;
    SET_GPR_S32(ctx, 12, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x19f33c: 0x182102a  slt         $v0, $t4, $v0
    ctx->pc = 0x19f33cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x19f340: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F340u;
    {
        const bool branch_taken_0x19f340 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F340u;
            // 0x19f344: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f340) {
            ctx->pc = 0x19F350u;
            goto label_19f350;
        }
    }
    ctx->pc = 0x19F348u;
    // 0x19f348: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x19F348u;
    {
        const bool branch_taken_0x19f348 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19f348) {
            ctx->pc = 0x19F360u;
            goto label_19f360;
        }
    }
    ctx->pc = 0x19F350u;
label_19f350:
    // 0x19f350: 0x17000003  bnez        $t8, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F350u;
    {
        const bool branch_taken_0x19f350 = (GPR_U64(ctx, 24) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F350u;
            // 0x19f354: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f350) {
            ctx->pc = 0x19F360u;
            goto label_19f360;
        }
    }
    ctx->pc = 0x19F358u;
    // 0x19f358: 0x1000ff7e  b           . + 4 + (-0x82 << 2)
    ctx->pc = 0x19F358u;
    {
        const bool branch_taken_0x19f358 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F35Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F358u;
            // 0x19f35c: 0x27180001  addiu       $t8, $t8, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f358) {
            ctx->pc = 0x19F154u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f154;
        }
    }
    ctx->pc = 0x19F360u;
label_19f360:
    // 0x19f360: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x19f360u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
label_19f364:
    // 0x19f364: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19f364u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19f368: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19f368u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19f36c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19f36cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19f370: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19f370u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f374: 0x3e00008  jr          $ra
    ctx->pc = 0x19F374u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F374u;
            // 0x19f378: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F154u: goto label_19f154;
            case 0x19F164u: goto label_19f164;
            case 0x19F180u: goto label_19f180;
            case 0x19F184u: goto label_19f184;
            case 0x19F18Cu: goto label_19f18c;
            case 0x19F1BCu: goto label_19f1bc;
            case 0x19F1E8u: goto label_19f1e8;
            case 0x19F1F0u: goto label_19f1f0;
            case 0x19F240u: goto label_19f240;
            case 0x19F24Cu: goto label_19f24c;
            case 0x19F268u: goto label_19f268;
            case 0x19F270u: goto label_19f270;
            case 0x19F2A0u: goto label_19f2a0;
            case 0x19F2CCu: goto label_19f2cc;
            case 0x19F2D0u: goto label_19f2d0;
            case 0x19F2FCu: goto label_19f2fc;
            case 0x19F318u: goto label_19f318;
            case 0x19F31Cu: goto label_19f31c;
            case 0x19F350u: goto label_19f350;
            case 0x19F360u: goto label_19f360;
            case 0x19F364u: goto label_19f364;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F37Cu;
    // 0x19f37c: 0x0  nop
    ctx->pc = 0x19f37cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
