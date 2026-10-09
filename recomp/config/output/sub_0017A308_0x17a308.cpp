#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A308
// Address: 0x17a308 - 0x17a370
void sub_0017A308_0x17a308(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A308_0x17a308");
#endif

    switch (ctx->pc) {
        case 0x17a32cu: goto label_17a32c;
        case 0x17a344u: goto label_17a344;
        default: break;
    }

    ctx->pc = 0x17a308u;

    // 0x17a308: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a308u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a30c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a30cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a310: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a310u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a314: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a314u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a318: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a318u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a31c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a31cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a320: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a324: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A324u;
    SET_GPR_U32(ctx, 31, 0x17A32Cu);
    ctx->pc = 0x17A328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A324u;
            // 0x17a328: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A32Cu; }
        if (ctx->pc != 0x17A32Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A32Cu; }
        if (ctx->pc != 0x17A32Cu) { return; }
    }
    ctx->pc = 0x17A32Cu;
label_17a32c:
    // 0x17a32c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a32cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a330: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a330u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a334: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x17A334u;
    {
        const bool branch_taken_0x17a334 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A334u;
            // 0x17a338: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a334) {
            ctx->pc = 0x17A358u;
            goto label_17a358;
        }
    }
    ctx->pc = 0x17A33Cu;
    // 0x17a33c: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A33Cu;
    SET_GPR_U32(ctx, 31, 0x17A344u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A344u; }
        if (ctx->pc != 0x17A344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A344u; }
        if (ctx->pc != 0x17A344u) { return; }
    }
    ctx->pc = 0x17A344u;
label_17a344:
    // 0x17a344: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A344u;
    {
        const bool branch_taken_0x17a344 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A344u;
            // 0x17a348: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a344) {
            ctx->pc = 0x17A35Cu;
            goto label_17a35c;
        }
    }
    ctx->pc = 0x17A34Cu;
    // 0x17a34c: 0x92230024  lbu         $v1, 0x24($s1)
    ctx->pc = 0x17a34cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x17a350: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a350u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a354: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a354u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a358:
    // 0x17a358: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a358u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a35c:
    // 0x17a35c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a35cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a360: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a360u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a364: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a364u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a368: 0x3e00008  jr          $ra
    ctx->pc = 0x17A368u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A36Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A368u;
            // 0x17a36c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A32Cu: goto label_17a32c;
            case 0x17A344u: goto label_17a344;
            case 0x17A358u: goto label_17a358;
            case 0x17A35Cu: goto label_17a35c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A370u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
