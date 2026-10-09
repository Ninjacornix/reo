#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D358
// Address: 0x13d358 - 0x13d3c0
void sub_0013D358_0x13d358(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D358_0x13d358");
#endif

    ctx->pc = 0x13d358u;

    // 0x13d358: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d358u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d35c: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x13d35cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d360: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D360u;
    {
        const bool branch_taken_0x13d360 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D360u;
            // 0x13d364: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d360) {
            ctx->pc = 0x13D380u;
            goto label_13d380;
        }
    }
    ctx->pc = 0x13D368u;
    // 0x13d368: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d368u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d36c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d36cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d370: 0x2484d368  addiu       $a0, $a0, -0x2C98
    ctx->pc = 0x13d370u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
    // 0x13d374: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13D374u;
    ctx->pc = 0x13D378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D374u;
            // 0x13d378: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13D37Cu;
    // 0x13d37c: 0x0  nop
    ctx->pc = 0x13d37cu;
    // NOP
label_13d380:
    // 0x13d380: 0x4620006  bltzl       $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D380u;
    {
        const bool branch_taken_0x13d380 = (GPR_S64(ctx, 3) < 0);
        if (branch_taken_0x13d380) {
            ctx->pc = 0x13D384u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D380u;
            // 0x13d384: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D39Cu;
            goto label_13d39c;
        }
    }
    ctx->pc = 0x13D388u;
    // 0x13d388: 0x8c820018  lw          $v0, 0x18($a0)
    ctx->pc = 0x13d388u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x13d38c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x13d38cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x13d390: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D390u;
    {
        const bool branch_taken_0x13d390 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D390u;
            // 0x13d394: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d390) {
            ctx->pc = 0x13D3B0u;
            goto label_13d3b0;
        }
    }
    ctx->pc = 0x13D398u;
    // 0x13d398: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d398u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_13d39c:
    // 0x13d39c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d39cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d3a0: 0x2484d400  addiu       $a0, $a0, -0x2C00
    ctx->pc = 0x13d3a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956032));
    // 0x13d3a4: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13D3A4u;
    ctx->pc = 0x13D3A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D3A4u;
            // 0x13d3a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13D3ACu;
    // 0x13d3ac: 0x0  nop
    ctx->pc = 0x13d3acu;
    // NOP
label_13d3b0:
    // 0x13d3b0: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x13d3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x13d3b4: 0x3e00008  jr          $ra
    ctx->pc = 0x13D3B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D3B4u;
            // 0x13d3b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D380u: goto label_13d380;
            case 0x13D39Cu: goto label_13d39c;
            case 0x13D3B0u: goto label_13d3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D3BCu;
    // 0x13d3bc: 0x0  nop
    ctx->pc = 0x13d3bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
