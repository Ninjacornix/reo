#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B11E0
// Address: 0x1b11e0 - 0x1b1260
void sub_001B11E0_0x1b11e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B11E0_0x1b11e0");
#endif

    switch (ctx->pc) {
        case 0x1b11f4u: goto label_1b11f4;
        case 0x1b1228u: goto label_1b1228;
        default: break;
    }

    ctx->pc = 0x1b11e0u;

    // 0x1b11e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b11e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b11e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b11e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b11e8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b11e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b11ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b11ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b11f0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b11f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b11f4:
    // 0x1b11f4: 0x11843c  dsll32      $s0, $s1, 16
    ctx->pc = 0x1b11f4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 17) << (32 + 16));
    // 0x1b11f8: 0x3c02004f  lui         $v0, 0x4F
    ctx->pc = 0x1b11f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)79 << 16));
    // 0x1b11fc: 0x10843f  dsra32      $s0, $s0, 16
    ctx->pc = 0x1b11fcu;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
    // 0x1b1200: 0x2442dd90  addiu       $v0, $v0, -0x2270
    ctx->pc = 0x1b1200u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958480));
    // 0x1b1204: 0x1018c0  sll         $v1, $s0, 3
    ctx->pc = 0x1b1204u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1b1208: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1208u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b120c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1b120cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b1210: 0x2406004c  addiu       $a2, $zero, 0x4C
    ctx->pc = 0x1b1210u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0x1b1214: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b1214u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b1218: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1b1218u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b121c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b121cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b1220: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B1220u;
    SET_GPR_U32(ctx, 31, 0x1B1228u);
    ctx->pc = 0x1B1224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1220u;
            // 0x1b1224: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1228u; }
        if (ctx->pc != 0x1B1228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1228u; }
        if (ctx->pc != 0x1B1228u) { return; }
    }
    ctx->pc = 0x1B1228u;
label_1b1228:
    // 0x1b1228: 0x26230001  addiu       $v1, $s1, 0x1
    ctx->pc = 0x1b1228u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b122c: 0x3c04004f  lui         $a0, 0x4F
    ctx->pc = 0x1b122cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)79 << 16));
    // 0x1b1230: 0x38c3c  dsll32      $s1, $v1, 16
    ctx->pc = 0x1b1230u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b1234: 0x2484c910  addiu       $a0, $a0, -0x36F0
    ctx->pc = 0x1b1234u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953232));
    // 0x1b1238: 0x118c3f  dsra32      $s1, $s1, 16
    ctx->pc = 0x1b1238u;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
    // 0x1b123c: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x1b123cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x1b1240: 0x2a230258  slti        $v1, $s1, 0x258
    ctx->pc = 0x1b1240u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)600) ? 1 : 0);
    // 0x1b1244: 0x1460ffeb  bnez        $v1, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1B1244u;
    {
        const bool branch_taken_0x1b1244 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B1248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1244u;
            // 0x1b1248: 0xa0800000  sb          $zero, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1244) {
            ctx->pc = 0x1B11F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b11f4;
        }
    }
    ctx->pc = 0x1B124Cu;
    // 0x1b124c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b124cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b1250: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b1250u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1254: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1254u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1258: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1258u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B125Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1258u;
            // 0x1b125c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B11F4u: goto label_1b11f4;
            case 0x1B1228u: goto label_1b1228;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1260u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
