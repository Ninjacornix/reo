#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116018
// Address: 0x116018 - 0x1160b0
void sub_00116018_0x116018(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116018_0x116018");
#endif

    ctx->pc = 0x116018u;

    // 0x116018: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x116018u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11601c: 0x51078  dsll        $v0, $a1, 1
    ctx->pc = 0x11601cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << 1);
    // 0x116020: 0x2357e  dsrl32      $a2, $v0, 21
    ctx->pc = 0x116020u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) >> (32 + 21));
    // 0x116024: 0x64c6fbcd  daddiu      $a2, $a2, -0x433
    ctx->pc = 0x116024u;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)4294966221);
    // 0x116028: 0x28c2ffcb  slti        $v0, $a2, -0x35
    ctx->pc = 0x116028u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294967243) ? 1 : 0);
    // 0x11602c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11602Cu;
    {
        const bool branch_taken_0x11602c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x116030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11602Cu;
            // 0x116030: 0x28c2000d  slti        $v0, $a2, 0xD (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)13) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11602c) {
            ctx->pc = 0x11603Cu;
            goto label_11603c;
        }
    }
    ctx->pc = 0x116034u;
    // 0x116034: 0x3e00008  jr          $ra
    ctx->pc = 0x116034u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116034u;
            // 0x116038: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11603Cu: goto label_11603c;
            case 0x11604Cu: goto label_11604c;
            case 0x116090u: goto label_116090;
            case 0x11609Cu: goto label_11609c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11603Cu;
label_11603c:
    // 0x11603c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11603Cu;
    {
        const bool branch_taken_0x11603c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x116040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11603Cu;
            // 0x116040: 0x51338  dsll        $v0, $a1, 12 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << 12);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11603c) {
            ctx->pc = 0x11604Cu;
            goto label_11604c;
        }
    }
    ctx->pc = 0x116044u;
    // 0x116044: 0x3e00008  jr          $ra
    ctx->pc = 0x116044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116044u;
            // 0x116048: 0x2402270f  addiu       $v0, $zero, 0x270F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9999));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11603Cu: goto label_11603c;
            case 0x11604Cu: goto label_11604c;
            case 0x116090u: goto label_116090;
            case 0x11609Cu: goto label_11609c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11604Cu;
label_11604c:
    // 0x11604c: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x11604cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x116050: 0x3197c  dsll32      $v1, $v1, 5
    ctx->pc = 0x116050u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 5));
    // 0x116054: 0x22b3a  dsrl        $a1, $v0, 12
    ctx->pc = 0x116054u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) >> 12);
    // 0x116058: 0x4c1000d  bgez        $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x116058u;
    {
        const bool branch_taken_0x116058 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x11605Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116058u;
            // 0x11605c: 0xa32825  or          $a1, $a1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116058) {
            ctx->pc = 0x116090u;
            goto label_116090;
        }
    }
    ctx->pc = 0x116060u;
    // 0x116060: 0x6302f  dsubu       $a2, $zero, $a2
    ctx->pc = 0x116060u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) - GPR_U64(ctx, 6));
    // 0x116064: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x116064u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x116068: 0x64c3fffe  daddiu      $v1, $a2, -0x2
    ctx->pc = 0x116068u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)4294967294);
    // 0x11606c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x11606cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x116070: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x116070u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x116074: 0x652816  dsrlv       $a1, $a1, $v1
    ctx->pc = 0x116074u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (GPR_U32(ctx, 3) & 0x3F));
    // 0x116078: 0x30a40003  andi        $a0, $a1, 0x3
    ctx->pc = 0x116078u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)3);
    // 0x11607c: 0x54820007  bnel        $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11607Cu;
    {
        const bool branch_taken_0x11607c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x11607c) {
            ctx->pc = 0x116080u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11607Cu;
            // 0x116080: 0x528ba  dsrl        $a1, $a1, 2 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> 2);
        ctx->in_delay_slot = false;
            ctx->pc = 0x11609Cu;
            goto label_11609c;
        }
    }
    ctx->pc = 0x116084u;
    // 0x116084: 0x510ba  dsrl        $v0, $a1, 2
    ctx->pc = 0x116084u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) >> 2);
    // 0x116088: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x116088u;
    {
        const bool branch_taken_0x116088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11608Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116088u;
            // 0x11608c: 0x64450001  daddiu      $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x116088) {
            ctx->pc = 0x11609Cu;
            goto label_11609c;
        }
    }
    ctx->pc = 0x116090u;
label_116090:
    // 0x116090: 0x6103c  dsll32      $v0, $a2, 0
    ctx->pc = 0x116090u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
    // 0x116094: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x116094u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x116098: 0x452814  dsllv       $a1, $a1, $v0
    ctx->pc = 0x116098u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (GPR_U32(ctx, 2) & 0x3F));
label_11609c:
    // 0x11609c: 0x5103c  dsll32      $v0, $a1, 0
    ctx->pc = 0x11609cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1160a0: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1160a0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1160a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1160A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11603Cu: goto label_11603c;
            case 0x11604Cu: goto label_11604c;
            case 0x116090u: goto label_116090;
            case 0x11609Cu: goto label_11609c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1160ACu;
    // 0x1160ac: 0x0  nop
    ctx->pc = 0x1160acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
