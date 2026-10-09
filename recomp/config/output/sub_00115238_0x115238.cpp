#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115238
// Address: 0x115238 - 0x1152a0
void sub_00115238_0x115238(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115238_0x115238");
#endif

    switch (ctx->pc) {
        case 0x115268u: goto label_115268;
        case 0x115270u: goto label_115270;
        case 0x115288u: goto label_115288;
        default: break;
    }

    ctx->pc = 0x115238u;

    // 0x115238: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x115238u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11523c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11523cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115240: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x115240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x115244: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x115244u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115248: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x115248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11524c: 0x40106000  mfc0        $s0, Status
    ctx->pc = 0x11524cu;
    SET_GPR_S32(ctx, 16, (int32_t)ctx->cop0_status);
    // 0x115250: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x115250u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x115254: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x115254u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x115258: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x115258u;
    {
        const bool branch_taken_0x115258 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x115258) {
            ctx->pc = 0x115268u;
            goto label_115268;
        }
    }
    ctx->pc = 0x115260u;
    // 0x115260: 0xc047598  jal         func_11D660
    ctx->pc = 0x115260u;
    SET_GPR_U32(ctx, 31, 0x115268u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115268u; }
        if (ctx->pc != 0x115268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115268u; }
        if (ctx->pc != 0x115268u) { return; }
    }
    ctx->pc = 0x115268u;
label_115268:
    // 0x115268: 0xc0450e0  jal         func_114380
    ctx->pc = 0x115268u;
    SET_GPR_U32(ctx, 31, 0x115270u);
    ctx->pc = 0x11526Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115268u;
            // 0x11526c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114380u;
    if (runtime->hasFunction(0x114380u)) {
        auto targetFn = runtime->lookupFunction(0x114380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115270u; }
        if (ctx->pc != 0x115270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114380_0x114380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115270u; }
        if (ctx->pc != 0x115270u) { return; }
    }
    ctx->pc = 0x115270u;
label_115270:
    // 0x115270: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x115270u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115274: 0xf  sync
    ctx->pc = 0x115274u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x115278: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x115278u;
    {
        const bool branch_taken_0x115278 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11527Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115278u;
            // 0x11527c: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115278) {
            ctx->pc = 0x11528Cu;
            goto label_11528c;
        }
    }
    ctx->pc = 0x115280u;
    // 0x115280: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x115280u;
    SET_GPR_U32(ctx, 31, 0x115288u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115288u; }
        if (ctx->pc != 0x115288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115288u; }
        if (ctx->pc != 0x115288u) { return; }
    }
    ctx->pc = 0x115288u;
label_115288:
    // 0x115288: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x115288u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_11528c:
    // 0x11528c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11528cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115290: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115290u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115294: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115294u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115298: 0x3e00008  jr          $ra
    ctx->pc = 0x115298u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11529Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115298u;
            // 0x11529c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115268u: goto label_115268;
            case 0x115270u: goto label_115270;
            case 0x115288u: goto label_115288;
            case 0x11528Cu: goto label_11528c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1152A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
