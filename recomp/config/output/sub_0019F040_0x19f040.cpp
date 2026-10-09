#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019F040
// Address: 0x19f040 - 0x19f110
void sub_0019F040_0x19f040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019F040_0x19f040");
#endif

    switch (ctx->pc) {
        case 0x19f080u: goto label_19f080;
        default: break;
    }

    ctx->pc = 0x19f040u;

    // 0x19f040: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f040u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f044: 0x8c22bed0  lw          $v0, -0x4130($at)
    ctx->pc = 0x19f044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950608)));
    // 0x19f048: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F048u;
    {
        const bool branch_taken_0x19f048 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F048u;
            // 0x19f04c: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f048) {
            ctx->pc = 0x19F058u;
            goto label_19f058;
        }
    }
    ctx->pc = 0x19F050u;
    // 0x19f050: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x19F050u;
    {
        const bool branch_taken_0x19f050 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F050u;
            // 0x19f054: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f050) {
            ctx->pc = 0x19F104u;
            goto label_19f104;
        }
    }
    ctx->pc = 0x19F058u;
label_19f058:
    // 0x19f058: 0x84430014  lh          $v1, 0x14($v0)
    ctx->pc = 0x19f058u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x19f05c: 0x8c26f9f8  lw          $a2, -0x608($at)
    ctx->pc = 0x19f05cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965752)));
    // 0x19f060: 0x10660025  beq         $v1, $a2, . + 4 + (0x25 << 2)
    ctx->pc = 0x19F060u;
    {
        const bool branch_taken_0x19f060 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        if (branch_taken_0x19f060) {
            ctx->pc = 0x19F0F8u;
            goto label_19f0f8;
        }
    }
    ctx->pc = 0x19F068u;
    // 0x19f068: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x19f068u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x19f06c: 0x64182b  sltu        $v1, $v1, $a0
    ctx->pc = 0x19f06cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x19f070: 0x14600021  bnez        $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x19F070u;
    {
        const bool branch_taken_0x19f070 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f070) {
            ctx->pc = 0x19F0F8u;
            goto label_19f0f8;
        }
    }
    ctx->pc = 0x19F078u;
    // 0x19f078: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x19F078u;
    {
        const bool branch_taken_0x19f078 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F07Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F078u;
            // 0x19f07c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f078) {
            ctx->pc = 0x19F104u;
            goto label_19f104;
        }
    }
    ctx->pc = 0x19F080u;
label_19f080:
    // 0x19f080: 0x84460014  lh          $a2, 0x14($v0)
    ctx->pc = 0x19f080u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x19f084: 0x84430016  lh          $v1, 0x16($v0)
    ctx->pc = 0x19f084u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 22)));
    // 0x19f088: 0x8c490004  lw          $t1, 0x4($v0)
    ctx->pc = 0x19f088u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x19f08c: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x19f08cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x19f090: 0xc51821  addu        $v1, $a2, $a1
    ctx->pc = 0x19f090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x19f094: 0x1520000c  bnez        $t1, . + 4 + (0xC << 2)
    ctx->pc = 0x19F094u;
    {
        const bool branch_taken_0x19f094 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F094u;
            // 0x19f098: 0xe34024  and         $t0, $a3, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 7) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f094) {
            ctx->pc = 0x19F0C8u;
            goto label_19f0c8;
        }
    }
    ctx->pc = 0x19F09Cu;
    // 0x19f09c: 0x28c34000  slti        $v1, $a2, 0x4000
    ctx->pc = 0x19f09cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16384) ? 1 : 0);
    // 0x19f0a0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F0A0u;
    {
        const bool branch_taken_0x19f0a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19F0A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F0A0u;
            // 0x19f0a4: 0x1041821  addu        $v1, $t0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f0a0) {
            ctx->pc = 0x19F0B0u;
            goto label_19f0b0;
        }
    }
    ctx->pc = 0x19F0A8u;
    // 0x19f0a8: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x19F0A8u;
    {
        const bool branch_taken_0x19f0a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F0ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F0A8u;
            // 0x19f0ac: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f0a8) {
            ctx->pc = 0x19F104u;
            goto label_19f104;
        }
    }
    ctx->pc = 0x19F0B0u;
label_19f0b0:
    // 0x19f0b0: 0x2c634000  sltiu       $v1, $v1, 0x4000
    ctx->pc = 0x19f0b0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)16384) ? 1 : 0);
    // 0x19f0b4: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x19F0B4u;
    {
        const bool branch_taken_0x19f0b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f0b4) {
            ctx->pc = 0x19F0C0u;
            goto label_19f0c0;
        }
    }
    ctx->pc = 0x19F0BCu;
    // 0x19f0bc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x19f0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_19f0c0:
    // 0x19f0c0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x19F0C0u;
    {
        const bool branch_taken_0x19f0c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19f0c0) {
            ctx->pc = 0x19F104u;
            goto label_19f104;
        }
    }
    ctx->pc = 0x19F0C8u;
label_19f0c8:
    // 0x19f0c8: 0x85230014  lh          $v1, 0x14($t1)
    ctx->pc = 0x19f0c8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 9), 20)));
    // 0x19f0cc: 0x103082b  sltu        $at, $t0, $v1
    ctx->pc = 0x19f0ccu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x19f0d0: 0x10200007  beqz        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x19F0D0u;
    {
        const bool branch_taken_0x19f0d0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x19f0d0) {
            ctx->pc = 0x19F0F0u;
            goto label_19f0f0;
        }
    }
    ctx->pc = 0x19F0D8u;
    // 0x19f0d8: 0x681823  subu        $v1, $v1, $t0
    ctx->pc = 0x19f0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19f0dc: 0x64182b  sltu        $v1, $v1, $a0
    ctx->pc = 0x19f0dcu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x19f0e0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F0E0u;
    {
        const bool branch_taken_0x19f0e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f0e0) {
            ctx->pc = 0x19F0F0u;
            goto label_19f0f0;
        }
    }
    ctx->pc = 0x19F0E8u;
    // 0x19f0e8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x19F0E8u;
    {
        const bool branch_taken_0x19f0e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x19f0e8) {
            ctx->pc = 0x19F104u;
            goto label_19f104;
        }
    }
    ctx->pc = 0x19F0F0u;
label_19f0f0:
    // 0x19f0f0: 0x1000ffe3  b           . + 4 + (-0x1D << 2)
    ctx->pc = 0x19F0F0u;
    {
        const bool branch_taken_0x19f0f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F0F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F0F0u;
            // 0x19f0f4: 0x120102d  daddu       $v0, $t1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f0f0) {
            ctx->pc = 0x19F080u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f080;
        }
    }
    ctx->pc = 0x19F0F8u;
label_19f0f8:
    // 0x19f0f8: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19f0f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19f0fc: 0x1000ffe0  b           . + 4 + (-0x20 << 2)
    ctx->pc = 0x19F0FCu;
    {
        const bool branch_taken_0x19f0fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F0FCu;
            // 0x19f100: 0xa03827  not         $a3, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 7, ~(GPR_U64(ctx, 5) | GPR_U64(ctx, 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f0fc) {
            ctx->pc = 0x19F080u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f080;
        }
    }
    ctx->pc = 0x19F104u;
label_19f104:
    // 0x19f104: 0x3e00008  jr          $ra
    ctx->pc = 0x19F104u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F058u: goto label_19f058;
            case 0x19F080u: goto label_19f080;
            case 0x19F0B0u: goto label_19f0b0;
            case 0x19F0C0u: goto label_19f0c0;
            case 0x19F0C8u: goto label_19f0c8;
            case 0x19F0F0u: goto label_19f0f0;
            case 0x19F0F8u: goto label_19f0f8;
            case 0x19F104u: goto label_19f104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F10Cu;
    // 0x19f10c: 0x0  nop
    ctx->pc = 0x19f10cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
