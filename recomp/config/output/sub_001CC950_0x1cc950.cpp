#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC950
// Address: 0x1cc950 - 0x1cc9b0
void sub_001CC950_0x1cc950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC950_0x1cc950");
#endif

    switch (ctx->pc) {
        case 0x1cc96cu: goto label_1cc96c;
        default: break;
    }

    ctx->pc = 0x1cc950u;

    // 0x1cc950: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cc950u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cc954: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cc954u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cc958: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cc958u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cc95c: 0x24841640  addiu       $a0, $a0, 0x1640
    ctx->pc = 0x1cc95cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 5696));
    // 0x1cc960: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc960u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc964: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1CC964u;
    SET_GPR_U32(ctx, 31, 0x1CC96Cu);
    ctx->pc = 0x1CC968u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC964u;
            // 0x1cc968: 0x24061000  addiu       $a2, $zero, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC96Cu; }
        if (ctx->pc != 0x1CC96Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC96Cu; }
        if (ctx->pc != 0x1CC96Cu) { return; }
    }
    ctx->pc = 0x1CC96Cu;
label_1cc96c:
    // 0x1cc96c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1cc96cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1cc970: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cc970u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cc974: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1cc974u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1cc978: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cc978u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cc97c: 0xac2366c8  sw          $v1, 0x66C8($at)
    ctx->pc = 0x1cc97cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26312), GPR_U32(ctx, 3));
    // 0x1cc980: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc980u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc984: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x1cc984u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x1cc988: 0xac240ae0  sw          $a0, 0xAE0($at)
    ctx->pc = 0x1cc988u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2784), GPR_U32(ctx, 4));
    // 0x1cc98c: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1cc98cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1cc990: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc990u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc994: 0xac230ad8  sw          $v1, 0xAD8($at)
    ctx->pc = 0x1cc994u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2776), GPR_U32(ctx, 3));
    // 0x1cc998: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc998u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc99c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC99Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC9A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC99Cu;
            // 0x1cc9a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC96Cu: goto label_1cc96c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC9A4u;
    // 0x1cc9a4: 0x0  nop
    ctx->pc = 0x1cc9a4u;
    // NOP
    // 0x1cc9a8: 0x0  nop
    ctx->pc = 0x1cc9a8u;
    // NOP
    // 0x1cc9ac: 0x0  nop
    ctx->pc = 0x1cc9acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
