#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001701F0
// Address: 0x1701f0 - 0x170268
void sub_001701F0_0x1701f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001701F0_0x1701f0");
#endif

    switch (ctx->pc) {
        case 0x17021cu: goto label_17021c;
        case 0x170240u: goto label_170240;
        default: break;
    }

    ctx->pc = 0x1701f0u;

    // 0x1701f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1701F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1701F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1701F0u;
            // 0x1701f4: 0x24a2fffc  addiu       $v0, $a1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967292));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17021Cu: goto label_17021c;
            case 0x170240u: goto label_170240;
            case 0x170248u: goto label_170248;
            case 0x17024Cu: goto label_17024c;
            case 0x170258u: goto label_170258;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1701F8u;
    // 0x1701f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1701f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1701fc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1701fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x170200: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x170200u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170204: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x170204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x170208: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x170208u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17020c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17020cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x170210: 0x8e301b30  lw          $s0, 0x1B30($s1)
    ctx->pc = 0x170210u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 6960)));
    // 0x170214: 0xc05c09a  jal         func_170268
    ctx->pc = 0x170214u;
    SET_GPR_U32(ctx, 31, 0x17021Cu);
    ctx->pc = 0x170218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170214u;
            // 0x170218: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170268u;
    if (runtime->hasFunction(0x170268u)) {
        auto targetFn = runtime->lookupFunction(0x170268u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17021Cu; }
        if (ctx->pc != 0x17021Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170268_0x170268(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17021Cu; }
        if (ctx->pc != 0x17021Cu) { return; }
    }
    ctx->pc = 0x17021Cu;
label_17021c:
    // 0x17021c: 0x5440000e  bnel        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x17021Cu;
    {
        const bool branch_taken_0x17021c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17021c) {
            ctx->pc = 0x170220u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17021Cu;
            // 0x170220: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x170258u;
            goto label_170258;
        }
    }
    ctx->pc = 0x170224u;
    // 0x170224: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x170224u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x170228: 0xae020074  sw          $v0, 0x74($s0)
    ctx->pc = 0x170228u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 116), GPR_U32(ctx, 2));
    // 0x17022c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x17022cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170230: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x170230u;
    {
        const bool branch_taken_0x170230 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x170234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170230u;
            // 0x170234: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170230) {
            ctx->pc = 0x170248u;
            goto label_170248;
        }
    }
    ctx->pc = 0x170238u;
    // 0x170238: 0xc05d58a  jal         func_175628
    ctx->pc = 0x170238u;
    SET_GPR_U32(ctx, 31, 0x170240u);
    ctx->pc = 0x17023Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170238u;
            // 0x17023c: 0x24050030  addiu       $a1, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170240u; }
        if (ctx->pc != 0x170240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170240u; }
        if (ctx->pc != 0x170240u) { return; }
    }
    ctx->pc = 0x170240u;
label_170240:
    // 0x170240: 0x54400002  bnel        $v0, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x170240u;
    {
        const bool branch_taken_0x170240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x170240) {
            ctx->pc = 0x170244u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x170240u;
            // 0x170244: 0x240200c8  addiu       $v0, $zero, 0xC8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17024Cu;
            goto label_17024c;
        }
    }
    ctx->pc = 0x170248u;
label_170248:
    // 0x170248: 0x240200c0  addiu       $v0, $zero, 0xC0
    ctx->pc = 0x170248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
label_17024c:
    // 0x17024c: 0xae020078  sw          $v0, 0x78($s0)
    ctx->pc = 0x17024cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 120), GPR_U32(ctx, 2));
    // 0x170250: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x170250u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170254: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x170254u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_170258:
    // 0x170258: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x170258u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17025c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17025cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x170260: 0x3e00008  jr          $ra
    ctx->pc = 0x170260u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170260u;
            // 0x170264: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17021Cu: goto label_17021c;
            case 0x170240u: goto label_170240;
            case 0x170248u: goto label_170248;
            case 0x17024Cu: goto label_17024c;
            case 0x170258u: goto label_170258;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170268u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
