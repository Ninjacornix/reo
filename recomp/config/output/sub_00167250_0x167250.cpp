#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167250
// Address: 0x167250 - 0x1672e0
void sub_00167250_0x167250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167250_0x167250");
#endif

    switch (ctx->pc) {
        case 0x167278u: goto label_167278;
        default: break;
    }

    ctx->pc = 0x167250u;

    // 0x167250: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x167250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x167254: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x167254u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167258: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x167258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16725c: 0x24500018  addiu       $s0, $v0, 0x18
    ctx->pc = 0x16725cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
    // 0x167260: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x167260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x167264: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x167264u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167268: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x167268u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16726c: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x16726cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x167270: 0xc059cb8  jal         func_1672E0
    ctx->pc = 0x167270u;
    SET_GPR_U32(ctx, 31, 0x167278u);
    ctx->pc = 0x167274u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167270u;
            // 0x167274: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1672E0u;
    if (runtime->hasFunction(0x1672E0u)) {
        auto targetFn = runtime->lookupFunction(0x1672E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167278u; }
        if (ctx->pc != 0x167278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001672E0_0x1672e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167278u; }
        if (ctx->pc != 0x167278u) { return; }
    }
    ctx->pc = 0x167278u;
label_167278:
    // 0x167278: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x167278u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16727c: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x16727cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167280: 0x64102b  sltu        $v0, $v1, $a0
    ctx->pc = 0x167280u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x167284: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x167284u;
    {
        const bool branch_taken_0x167284 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x167284) {
            ctx->pc = 0x167288u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167284u;
            // 0x167288: 0x8fa40010  lw          $a0, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1672A4u;
            goto label_1672a4;
        }
    }
    ctx->pc = 0x16728Cu;
    // 0x16728c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x16728cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x167290: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x167290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167294: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x167294u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x167298: 0x5440000d  bnel        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x167298u;
    {
        const bool branch_taken_0x167298 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x167298) {
            ctx->pc = 0x16729Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167298u;
            // 0x16729c: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1672D0u;
            goto label_1672d0;
        }
    }
    ctx->pc = 0x1672A0u;
    // 0x1672a0: 0x8fa40010  lw          $a0, 0x10($sp)
    ctx->pc = 0x1672a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1672a4:
    // 0x1672a4: 0x64102b  sltu        $v0, $v1, $a0
    ctx->pc = 0x1672a4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1672a8: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1672A8u;
    {
        const bool branch_taken_0x1672a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1672a8) {
            ctx->pc = 0x1672ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1672A8u;
            // 0x1672ac: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1672C8u;
            goto label_1672c8;
        }
    }
    ctx->pc = 0x1672B0u;
    // 0x1672b0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x1672b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x1672b4: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1672b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1672b8: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1672b8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1672bc: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1672BCu;
    {
        const bool branch_taken_0x1672bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1672bc) {
            ctx->pc = 0x1672C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1672BCu;
            // 0x1672c0: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1672D0u;
            goto label_1672d0;
        }
    }
    ctx->pc = 0x1672C4u;
    // 0x1672c4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1672c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_1672c8:
    // 0x1672c8: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1672c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1672cc: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1672ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1672d0:
    // 0x1672d0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1672d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1672d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1672D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1672D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1672D4u;
            // 0x1672d8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167278u: goto label_167278;
            case 0x1672A4u: goto label_1672a4;
            case 0x1672C8u: goto label_1672c8;
            case 0x1672D0u: goto label_1672d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1672DCu;
    // 0x1672dc: 0x0  nop
    ctx->pc = 0x1672dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
