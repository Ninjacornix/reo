#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150110
// Address: 0x150110 - 0x1501e8
void sub_00150110_0x150110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150110_0x150110");
#endif

    switch (ctx->pc) {
        case 0x150160u: goto label_150160;
        case 0x150198u: goto label_150198;
        case 0x1501a0u: goto label_1501a0;
        default: break;
    }

    ctx->pc = 0x150110u;

    // 0x150110: 0x80582d  daddu       $t3, $a0, $zero
    ctx->pc = 0x150110u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150114: 0xa0702d  daddu       $t6, $a1, $zero
    ctx->pc = 0x150114u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150118: 0x8d630004  lw          $v1, 0x4($t3)
    ctx->pc = 0x150118u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 4)));
    // 0x15011c: 0xc0682d  daddu       $t5, $a2, $zero
    ctx->pc = 0x15011cu;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150120: 0x8d620008  lw          $v0, 0x8($t3)
    ctx->pc = 0x150120u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x150124: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x150124u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150128: 0x2467000f  addiu       $a3, $v1, 0xF
    ctx->pc = 0x150128u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x15012c: 0x28650000  slti        $a1, $v1, 0x0
    ctx->pc = 0x15012cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x150130: 0x2446001f  addiu       $a2, $v0, 0x1F
    ctx->pc = 0x150130u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 31));
    // 0x150134: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x150134u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x150138: 0xe5180b  movn        $v1, $a3, $a1
    ctx->pc = 0x150138u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 7));
    // 0x15013c: 0xc4100b  movn        $v0, $a2, $a0
    ctx->pc = 0x15013cu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x150140: 0x23943  sra         $a3, $v0, 5
    ctx->pc = 0x150140u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 2), 5));
    // 0x150144: 0x36103  sra         $t4, $v1, 4
    ctx->pc = 0x150144u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 3), 4));
    // 0x150148: 0x77840  sll         $t7, $a3, 1
    ctx->pc = 0x150148u;
    SET_GPR_S32(ctx, 15, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x15014c: 0x8d690000  lw          $t1, 0x0($t3)
    ctx->pc = 0x15014cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x150150: 0x19800023  blez        $t4, . + 4 + (0x23 << 2)
    ctx->pc = 0x150150u;
    {
        const bool branch_taken_0x150150 = (GPR_S64(ctx, 12) <= 0);
        ctx->pc = 0x150154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150150u;
            // 0x150154: 0x8dc60000  lw          $a2, 0x0($t6) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150150) {
            ctx->pc = 0x1501E0u;
            goto label_1501e0;
        }
    }
    ctx->pc = 0x150158u;
    // 0x150158: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x150158u;
    {
        const bool branch_taken_0x150158 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15015Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150158u;
            // 0x15015c: 0xea2018  mult        $a0, $a3, $t2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x150158) {
            ctx->pc = 0x150168u;
            goto label_150168;
        }
    }
    ctx->pc = 0x150160u;
label_150160:
    // 0x150160: 0x8dc60000  lw          $a2, 0x0($t6)
    ctx->pc = 0x150160u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x150164: 0xea2018  mult        $a0, $a3, $t2
    ctx->pc = 0x150164u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
label_150168:
    // 0x150168: 0x1e72821  addu        $a1, $t7, $a3
    ctx->pc = 0x150168u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 7)));
    // 0x15016c: 0x529c0  sll         $a1, $a1, 7
    ctx->pc = 0x15016cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 7));
    // 0x150170: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x150170u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150174: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x150174u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x150178: 0x41a80  sll         $v1, $a0, 10
    ctx->pc = 0x150178u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 10));
    // 0x15017c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x15017cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x150180: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x150180u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x150184: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x150184u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x150188: 0x24660003  addiu       $a2, $v1, 0x3
    ctx->pc = 0x150188u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x15018c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x15018cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x150190: 0x18e0000f  blez        $a3, . + 4 + (0xF << 2)
    ctx->pc = 0x150190u;
    {
        const bool branch_taken_0x150190 = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x150194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150190u;
            // 0x150194: 0x492021  addu        $a0, $v0, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150190) {
            ctx->pc = 0x1501D0u;
            goto label_1501d0;
        }
    }
    ctx->pc = 0x150198u;
label_150198:
    // 0x150198: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x150198u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x15019c: 0x0  nop
    ctx->pc = 0x15019cu;
    // NOP
label_1501a0:
    // 0x1501a0: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x1501a0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1501a4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1501a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1501a8: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1501a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1501ac: 0x1a31821  addu        $v1, $t5, $v1
    ctx->pc = 0x1501acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 3)));
    // 0x1501b0: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x1501b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1501b4: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x1501b4u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1501b8: 0x4a1fff9  bgez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1501B8u;
    {
        const bool branch_taken_0x1501b8 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x1501BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1501B8u;
            // 0x1501bc: 0x24c60004  addiu       $a2, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1501b8) {
            ctx->pc = 0x1501A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1501a0;
        }
    }
    ctx->pc = 0x1501C0u;
    // 0x1501c0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1501c0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1501c4: 0x107102a  slt         $v0, $t0, $a3
    ctx->pc = 0x1501c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1501c8: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1501C8u;
    {
        const bool branch_taken_0x1501c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1501CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1501C8u;
            // 0x1501cc: 0x24840080  addiu       $a0, $a0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1501c8) {
            ctx->pc = 0x150198u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150198;
        }
    }
    ctx->pc = 0x1501D0u;
label_1501d0:
    // 0x1501d0: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1501d0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1501d4: 0x14c102a  slt         $v0, $t2, $t4
    ctx->pc = 0x1501d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 12)) ? 1 : 0);
    // 0x1501d8: 0x5440ffe1  bnel        $v0, $zero, . + 4 + (-0x1F << 2)
    ctx->pc = 0x1501D8u;
    {
        const bool branch_taken_0x1501d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1501d8) {
            ctx->pc = 0x1501DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1501D8u;
            // 0x1501dc: 0x8d690000  lw          $t1, 0x0($t3) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x150160u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150160;
        }
    }
    ctx->pc = 0x1501E0u;
label_1501e0:
    // 0x1501e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1501E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150160u: goto label_150160;
            case 0x150168u: goto label_150168;
            case 0x150198u: goto label_150198;
            case 0x1501A0u: goto label_1501a0;
            case 0x1501D0u: goto label_1501d0;
            case 0x1501E0u: goto label_1501e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1501E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
