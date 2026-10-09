#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0450
// Address: 0x1c0450 - 0x1c04e0
void sub_001C0450_0x1c0450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0450_0x1c0450");
#endif

    switch (ctx->pc) {
        case 0x1c04a4u: goto label_1c04a4;
        default: break;
    }

    ctx->pc = 0x1c0450u;

    // 0x1c0450: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0450u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0454: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c0454u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0458: 0xac206c50  sw          $zero, 0x6C50($at)
    ctx->pc = 0x1c0458u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27728), GPR_U32(ctx, 0));
    // 0x1c045c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c045cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0460: 0xac206c54  sw          $zero, 0x6C54($at)
    ctx->pc = 0x1c0460u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27732), GPR_U32(ctx, 0));
    // 0x1c0464: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0464u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0468: 0xac236ce8  sw          $v1, 0x6CE8($at)
    ctx->pc = 0x1c0468u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27880), GPR_U32(ctx, 3));
    // 0x1c046c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c046cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c0470: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0470u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c0474: 0xac236c74  sw          $v1, 0x6C74($at)
    ctx->pc = 0x1c0474u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 27764), GPR_U32(ctx, 3));
    // 0x1c0478: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c0478u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c047c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C047Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C047Cu;
            // 0x1c0480: 0xac206c64  sw          $zero, 0x6C64($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 27748), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C04A4u: goto label_1c04a4;
            case 0x1C04CCu: goto label_1c04cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C0484u;
    // 0x1c0484: 0x0  nop
    ctx->pc = 0x1c0484u;
    // NOP
    // 0x1c0488: 0x0  nop
    ctx->pc = 0x1c0488u;
    // NOP
    // 0x1c048c: 0x0  nop
    ctx->pc = 0x1c048cu;
    // NOP
    // 0x1c0490: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0494: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c0498: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c0498u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c049c: 0xc06fe10  jal         func_1BF840
    ctx->pc = 0x1C049Cu;
    SET_GPR_U32(ctx, 31, 0x1C04A4u);
    ctx->pc = 0x1C04A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C049Cu;
            // 0x1c04a0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BF840u;
    if (runtime->hasFunction(0x1BF840u)) {
        auto targetFn = runtime->lookupFunction(0x1BF840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C04A4u; }
        if (ctx->pc != 0x1C04A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF840_0x1bf840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C04A4u; }
        if (ctx->pc != 0x1C04A4u) { return; }
    }
    ctx->pc = 0x1C04A4u;
label_1c04a4:
    // 0x1c04a4: 0x4400009  bltz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C04A4u;
    {
        const bool branch_taken_0x1c04a4 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c04a4) {
            ctx->pc = 0x1C04CCu;
            goto label_1c04cc;
        }
    }
    ctx->pc = 0x1C04ACu;
    // 0x1c04ac: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1c04acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1c04b0: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x1c04b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c04b4: 0xae040014  sw          $a0, 0x14($s0)
    ctx->pc = 0x1c04b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 4));
    // 0x1c04b8: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1c04b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c04bc: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1c04bcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c04c0: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C04C0u;
    {
        const bool branch_taken_0x1c04c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c04c0) {
            ctx->pc = 0x1C04CCu;
            goto label_1c04cc;
        }
    }
    ctx->pc = 0x1C04C8u;
    // 0x1c04c8: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x1c04c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
label_1c04cc:
    // 0x1c04cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c04ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c04d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c04d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c04d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C04D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C04D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C04D4u;
            // 0x1c04d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C04A4u: goto label_1c04a4;
            case 0x1C04CCu: goto label_1c04cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C04DCu;
    // 0x1c04dc: 0x0  nop
    ctx->pc = 0x1c04dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
