#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117958
// Address: 0x117958 - 0x1179e4
void sub_00117958_0x117958(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117958_0x117958");
#endif

    ctx->pc = 0x117958u;

    // 0x117958: 0x8c850034  lw          $a1, 0x34($a0)
    ctx->pc = 0x117958u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 52)));
    // 0x11795c: 0x8ca60040  lw          $a2, 0x40($a1)
    ctx->pc = 0x11795cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x117960: 0x8cc2000c  lw          $v0, 0xC($a2)
    ctx->pc = 0x117960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x117964: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x117964u;
    {
        const bool branch_taken_0x117964 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117964) {
            ctx->pc = 0x117968u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117964u;
            // 0x117968: 0x8cc20010  lw          $v0, 0x10($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117974u;
            goto label_117974;
        }
    }
    ctx->pc = 0x11796Cu;
    // 0x11796c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x11796Cu;
    {
        const bool branch_taken_0x11796c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11796Cu;
            // 0x117970: 0xacc5000c  sw          $a1, 0xC($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11796c) {
            ctx->pc = 0x117978u;
            goto label_117978;
        }
    }
    ctx->pc = 0x117974u;
label_117974:
    // 0x117974: 0xac45003c  sw          $a1, 0x3C($v0)
    ctx->pc = 0x117974u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 5));
label_117978:
    // 0x117978: 0xacc50010  sw          $a1, 0x10($a2)
    ctx->pc = 0x117978u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 5));
    // 0x11797c: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x11797cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x117980: 0x8c83001c  lw          $v1, 0x1C($a0)
    ctx->pc = 0x117980u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x117984: 0xaca20020  sw          $v0, 0x20($a1)
    ctx->pc = 0x117984u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 32), GPR_U32(ctx, 2));
    // 0x117988: 0xaca3001c  sw          $v1, 0x1C($a1)
    ctx->pc = 0x117988u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 3));
    // 0x11798c: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x11798cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x117990: 0xaca20024  sw          $v0, 0x24($a1)
    ctx->pc = 0x117990u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 2));
    // 0x117994: 0x8c830024  lw          $v1, 0x24($a0)
    ctx->pc = 0x117994u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x117998: 0xaca3000c  sw          $v1, 0xC($a1)
    ctx->pc = 0x117998u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 3));
    // 0x11799c: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x11799cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1179a0: 0xaca20028  sw          $v0, 0x28($a1)
    ctx->pc = 0x1179a0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 40), GPR_U32(ctx, 2));
    // 0x1179a4: 0x8c83002c  lw          $v1, 0x2C($a0)
    ctx->pc = 0x1179a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x1179a8: 0xaca3002c  sw          $v1, 0x2C($a1)
    ctx->pc = 0x1179a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 44), GPR_U32(ctx, 3));
    // 0x1179ac: 0x8c820030  lw          $v0, 0x30($a0)
    ctx->pc = 0x1179acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x1179b0: 0xaca20030  sw          $v0, 0x30($a1)
    ctx->pc = 0x1179b0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 48), GPR_U32(ctx, 2));
    // 0x1179b4: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x1179b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1179b8: 0xaca30034  sw          $v1, 0x34($a1)
    ctx->pc = 0x1179b8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 52), GPR_U32(ctx, 3));
    // 0x1179bc: 0x8cc40000  lw          $a0, 0x0($a2)
    ctx->pc = 0x1179bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1179c0: 0x4800006  bltz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1179C0u;
    {
        const bool branch_taken_0x1179c0 = (GPR_S64(ctx, 4) < 0);
        if (branch_taken_0x1179c0) {
            ctx->pc = 0x1179DCu;
            goto label_1179dc;
        }
    }
    ctx->pc = 0x1179C8u;
    // 0x1179c8: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x1179c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1179cc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1179CCu;
    {
        const bool branch_taken_0x1179cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1179cc) {
            ctx->pc = 0x1179DCu;
            goto label_1179dc;
        }
    }
    ctx->pc = 0x1179D4u;
    // 0x1179d4: 0x8045534  j           func_1154D0
    ctx->pc = 0x1179D4u;
    ctx->pc = 0x1154D0u;
    if (runtime->hasFunction(0x1154D0u)) {
        auto targetFn = runtime->lookupFunction(0x1154D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001154D0_0x1154d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1179DCu;
label_1179dc:
    // 0x1179dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1179DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117974u: goto label_117974;
            case 0x117978u: goto label_117978;
            case 0x1179DCu: goto label_1179dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1179E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
