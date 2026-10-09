#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A730
// Address: 0x10a730 - 0x10a78c
void sub_0010A730_0x10a730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A730_0x10a730");
#endif

    switch (ctx->pc) {
        case 0x10a75cu: goto label_10a75c;
        default: break;
    }

    ctx->pc = 0x10a730u;

    // 0x10a730: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10a730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10a734: 0x3c020037  lui         $v0, 0x37
    ctx->pc = 0x10a734u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)55 << 16));
    // 0x10a738: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a738u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a73c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10a73cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a740: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10a740u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10a744: 0x2451f0dc  addiu       $s1, $v0, -0xF24
    ctx->pc = 0x10a744u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963420));
    // 0x10a748: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x10a748u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a74c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x10a74cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a750: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x10a750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x10a754: 0xc04537e  jal         func_114DF8
    ctx->pc = 0x10A754u;
    SET_GPR_U32(ctx, 31, 0x10A75Cu);
    ctx->pc = 0x10A758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A754u;
            // 0x10a758: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114DF8u;
    if (runtime->hasFunction(0x114DF8u)) {
        auto targetFn = runtime->lookupFunction(0x114DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A75Cu; }
        if (ctx->pc != 0x10A75Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114DF8_0x114df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A75Cu; }
        if (ctx->pc != 0x10A75Cu) { return; }
    }
    ctx->pc = 0x10A75Cu;
label_10a75c:
    // 0x10a75c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x10a75cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a760: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x10a760u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a764: 0x54640005  bnel        $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10A764u;
    {
        const bool branch_taken_0x10a764 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x10a764) {
            ctx->pc = 0x10A768u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A764u;
            // 0x10a768: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A77Cu;
            goto label_10a77c;
        }
    }
    ctx->pc = 0x10A76Cu;
    // 0x10a76c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x10a76cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x10a770: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10A770u;
    {
        const bool branch_taken_0x10a770 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a770) {
            ctx->pc = 0x10A774u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A770u;
            // 0x10a774: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A778u;
            goto label_10a778;
        }
    }
    ctx->pc = 0x10A778u;
label_10a778:
    // 0x10a778: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a778u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_10a77c:
    // 0x10a77c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10a77cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a780: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10a780u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10a784: 0x3e00008  jr          $ra
    ctx->pc = 0x10A784u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A784u;
            // 0x10a788: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A75Cu: goto label_10a75c;
            case 0x10A778u: goto label_10a778;
            case 0x10A77Cu: goto label_10a77c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A78Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
