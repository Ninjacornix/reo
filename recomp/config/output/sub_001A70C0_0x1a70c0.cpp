#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A70C0
// Address: 0x1a70c0 - 0x1a7120
void sub_001A70C0_0x1a70c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A70C0_0x1a70c0");
#endif

    switch (ctx->pc) {
        case 0x1a70d4u: goto label_1a70d4;
        case 0x1a70e8u: goto label_1a70e8;
        case 0x1a70f8u: goto label_1a70f8;
        case 0x1a7108u: goto label_1a7108;
        default: break;
    }

    ctx->pc = 0x1a70c0u;

    // 0x1a70c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a70c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a70c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a70c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a70c8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a70c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a70cc: 0xc045144  jal         func_114510
    ctx->pc = 0x1A70CCu;
    SET_GPR_U32(ctx, 31, 0x1A70D4u);
    ctx->pc = 0x1A70D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A70CCu;
            // 0x1a70d0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70D4u; }
        if (ctx->pc != 0x1A70D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70D4u; }
        if (ctx->pc != 0x1A70D4u) { return; }
    }
    ctx->pc = 0x1A70D4u;
label_1a70d4:
    // 0x1a70d4: 0x3c05001a  lui         $a1, 0x1A
    ctx->pc = 0x1a70d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)26 << 16));
    // 0x1a70d8: 0x3204ffff  andi        $a0, $s0, 0xFFFF
    ctx->pc = 0x1a70d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x1a70dc: 0x24a57090  addiu       $a1, $a1, 0x7090
    ctx->pc = 0x1a70dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 28816));
    // 0x1a70e0: 0xc0450e8  jal         func_1143A0
    ctx->pc = 0x1A70E0u;
    SET_GPR_U32(ctx, 31, 0x1A70E8u);
    ctx->pc = 0x1A70E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A70E0u;
            // 0x1a70e4: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1143A0u;
    if (runtime->hasFunction(0x1143A0u)) {
        auto targetFn = runtime->lookupFunction(0x1143A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70E8u; }
        if (ctx->pc != 0x1A70E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001143A0_0x1143a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70E8u; }
        if (ctx->pc != 0x1A70E8u) { return; }
    }
    ctx->pc = 0x1A70E8u;
label_1a70e8:
    // 0x1a70e8: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A70E8u;
    {
        const bool branch_taken_0x1a70e8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1A70ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A70E8u;
            // 0x1a70ec: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a70e8) {
            ctx->pc = 0x1A7100u;
            goto label_1a7100;
        }
    }
    ctx->pc = 0x1A70F0u;
    // 0x1a70f0: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A70F0u;
    SET_GPR_U32(ctx, 31, 0x1A70F8u);
    ctx->pc = 0x1A70F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A70F0u;
            // 0x1a70f4: 0x24841f70  addiu       $a0, $a0, 0x1F70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70F8u; }
        if (ctx->pc != 0x1A70F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A70F8u; }
        if (ctx->pc != 0x1A70F8u) { return; }
    }
    ctx->pc = 0x1A70F8u;
label_1a70f8:
    // 0x1a70f8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A70F8u;
    {
        const bool branch_taken_0x1a70f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A70FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A70F8u;
            // 0x1a70fc: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a70f8) {
            ctx->pc = 0x1A7108u;
            goto label_1a7108;
        }
    }
    ctx->pc = 0x1A7100u;
label_1a7100:
    // 0x1a7100: 0xc045150  jal         func_114540
    ctx->pc = 0x1A7100u;
    SET_GPR_U32(ctx, 31, 0x1A7108u);
    ctx->pc = 0x114540u;
    if (runtime->hasFunction(0x114540u)) {
        auto targetFn = runtime->lookupFunction(0x114540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7108u; }
        if (ctx->pc != 0x1A7108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114540_0x114540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7108u; }
        if (ctx->pc != 0x1A7108u) { return; }
    }
    ctx->pc = 0x1A7108u;
label_1a7108:
    // 0x1a7108: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a7108u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a710c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a710cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7110: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7110u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7110u;
            // 0x1a7114: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A70D4u: goto label_1a70d4;
            case 0x1A70E8u: goto label_1a70e8;
            case 0x1A70F8u: goto label_1a70f8;
            case 0x1A7100u: goto label_1a7100;
            case 0x1A7108u: goto label_1a7108;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7118u;
    // 0x1a7118: 0x0  nop
    ctx->pc = 0x1a7118u;
    // NOP
    // 0x1a711c: 0x0  nop
    ctx->pc = 0x1a711cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
