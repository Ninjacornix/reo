#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100220
// Address: 0x100220 - 0x100298
void sub_00100220_0x100220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100220_0x100220");
#endif

    switch (ctx->pc) {
        case 0x10024cu: goto label_10024c;
        case 0x10025cu: goto label_10025c;
        case 0x100280u: goto label_100280;
        default: break;
    }

    ctx->pc = 0x100220u;

    // 0x100220: 0x24030023  addiu       $v1, $zero, 0x23
    ctx->pc = 0x100220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
    // 0x100224: 0xc  syscall     0
    ctx->pc = 0x100224u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x100228: 0x0  nop
    ctx->pc = 0x100228u;
    // NOP
    // 0x10022c: 0x0  nop
    ctx->pc = 0x10022cu;
    // NOP
    // 0x100230: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x100230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x100234: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100238: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x100238u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10023c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x10023cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x100240: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x100240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x100244: 0xc04035e  jal         func_100D78
    ctx->pc = 0x100244u;
    SET_GPR_U32(ctx, 31, 0x10024Cu);
    ctx->pc = 0x100248u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100244u;
            // 0x100248: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10024Cu; }
        if (ctx->pc != 0x10024Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10024Cu; }
        if (ctx->pc != 0x10024Cu) { return; }
    }
    ctx->pc = 0x10024Cu;
label_10024c:
    // 0x10024c: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x10024Cu;
    {
        const bool branch_taken_0x10024c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x100250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10024Cu;
            // 0x100250: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10024c) {
            ctx->pc = 0x100284u;
            goto label_100284;
        }
    }
    ctx->pc = 0x100254u;
    // 0x100254: 0xc047598  jal         func_11D660
    ctx->pc = 0x100254u;
    SET_GPR_U32(ctx, 31, 0x10025Cu);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10025Cu; }
        if (ctx->pc != 0x10025Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10025Cu; }
        if (ctx->pc != 0x10025Cu) { return; }
    }
    ctx->pc = 0x10025Cu;
label_10025c:
    // 0x10025c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x10025cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x100260: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x100260u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x100264: 0x8c709f80  lw          $s0, -0x6080($v1)
    ctx->pc = 0x100264u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942592)));
    // 0x100268: 0xac719f80  sw          $s1, -0x6080($v1)
    ctx->pc = 0x100268u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942592), GPR_U32(ctx, 17));
    // 0x10026c: 0xac9c9f84  sw          $gp, -0x607C($a0)
    ctx->pc = 0x10026cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294942596), GPR_U32(ctx, 28));
    // 0x100270: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x100270u;
    {
        const bool branch_taken_0x100270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x100274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100270u;
            // 0x100274: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100270) {
            ctx->pc = 0x100284u;
            goto label_100284;
        }
    }
    ctx->pc = 0x100278u;
    // 0x100278: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x100278u;
    SET_GPR_U32(ctx, 31, 0x100280u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100280u; }
        if (ctx->pc != 0x100280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100280u; }
        if (ctx->pc != 0x100280u) { return; }
    }
    ctx->pc = 0x100280u;
label_100280:
    // 0x100280: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x100280u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_100284:
    // 0x100284: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x100284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100288: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x100288u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10028c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10028cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100290: 0x3e00008  jr          $ra
    ctx->pc = 0x100290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100290u;
            // 0x100294: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10024Cu: goto label_10024c;
            case 0x10025Cu: goto label_10025c;
            case 0x100280u: goto label_100280;
            case 0x100284u: goto label_100284;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100298u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
