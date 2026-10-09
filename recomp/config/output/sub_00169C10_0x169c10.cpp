#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169C10
// Address: 0x169c10 - 0x169c80
void sub_00169C10_0x169c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169C10_0x169c10");
#endif

    switch (ctx->pc) {
        case 0x169c44u: goto label_169c44;
        case 0x169c58u: goto label_169c58;
        default: break;
    }

    ctx->pc = 0x169c10u;

    // 0x169c10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x169c10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x169c14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x169c14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169c18: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x169c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x169c1c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x169c1cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169c20: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x169c24: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x169c24u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169c28: 0x12200010  beqz        $s1, . + 4 + (0x10 << 2)
    ctx->pc = 0x169C28u;
    {
        const bool branch_taken_0x169c28 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x169C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169C28u;
            // 0x169c2c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169c28) {
            ctx->pc = 0x169C6Cu;
            goto label_169c6c;
        }
    }
    ctx->pc = 0x169C30u;
    // 0x169c30: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x169C30u;
    {
        const bool branch_taken_0x169c30 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x169c30) {
            ctx->pc = 0x169C50u;
            goto label_169c50;
        }
    }
    ctx->pc = 0x169C38u;
    // 0x169c38: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x169c38u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x169c3c: 0xc05a720  jal         func_169C80
    ctx->pc = 0x169C3Cu;
    SET_GPR_U32(ctx, 31, 0x169C44u);
    ctx->pc = 0x169C40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169C3Cu;
            // 0x169c40: 0x2484f124  addiu       $a0, $a0, -0xEDC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963492));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C80u;
    if (runtime->hasFunction(0x169C80u)) {
        auto targetFn = runtime->lookupFunction(0x169C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169C44u; }
        if (ctx->pc != 0x169C44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C80_0x169c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169C44u; }
        if (ctx->pc != 0x169C44u) { return; }
    }
    ctx->pc = 0x169C44u;
label_169c44:
    // 0x169c44: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x169C44u;
    {
        const bool branch_taken_0x169c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x169C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169C44u;
            // 0x169c48: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169c44) {
            ctx->pc = 0x169C6Cu;
            goto label_169c6c;
        }
    }
    ctx->pc = 0x169C4Cu;
    // 0x169c4c: 0x0  nop
    ctx->pc = 0x169c4cu;
    // NOP
label_169c50:
    // 0x169c50: 0xc05a720  jal         func_169C80
    ctx->pc = 0x169C50u;
    SET_GPR_U32(ctx, 31, 0x169C58u);
    ctx->pc = 0x169C54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169C50u;
            // 0x169c54: 0x2604098c  addiu       $a0, $s0, 0x98C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2444));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C80u;
    if (runtime->hasFunction(0x169C80u)) {
        auto targetFn = runtime->lookupFunction(0x169C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169C58u; }
        if (ctx->pc != 0x169C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C80_0x169c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169C58u; }
        if (ctx->pc != 0x169C58u) { return; }
    }
    ctx->pc = 0x169C58u;
label_169c58:
    // 0x169c58: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x169c58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x169c5c: 0x18400002  blez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x169C5Cu;
    {
        const bool branch_taken_0x169c5c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x169C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169C5Cu;
            // 0x169c60: 0x21823  negu        $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169c5c) {
            ctx->pc = 0x169C68u;
            goto label_169c68;
        }
    }
    ctx->pc = 0x169C64u;
    // 0x169c64: 0xae030048  sw          $v1, 0x48($s0)
    ctx->pc = 0x169c64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 3));
label_169c68:
    // 0x169c68: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x169c68u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_169c6c:
    // 0x169c6c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169c6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169c70: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x169c70u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169c74: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x169c74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169c78: 0x3e00008  jr          $ra
    ctx->pc = 0x169C78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169C78u;
            // 0x169c7c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169C44u: goto label_169c44;
            case 0x169C50u: goto label_169c50;
            case 0x169C58u: goto label_169c58;
            case 0x169C68u: goto label_169c68;
            case 0x169C6Cu: goto label_169c6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169C80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
