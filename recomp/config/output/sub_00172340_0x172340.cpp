#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172340
// Address: 0x172340 - 0x1723b0
void sub_00172340_0x172340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172340_0x172340");
#endif

    switch (ctx->pc) {
        case 0x17235cu: goto label_17235c;
        case 0x172394u: goto label_172394;
        default: break;
    }

    ctx->pc = 0x172340u;

    // 0x172340: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x172340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x172344: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172348: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x172348u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17234c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17234cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x172350: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x172350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x172354: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x172354u;
    SET_GPR_U32(ctx, 31, 0x17235Cu);
    ctx->pc = 0x172358u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172354u;
            // 0x172358: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17235Cu; }
        if (ctx->pc != 0x17235Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17235Cu; }
        if (ctx->pc != 0x17235Cu) { return; }
    }
    ctx->pc = 0x17235Cu;
label_17235c:
    // 0x17235c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17235cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x172360: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x172360u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172364: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x172364u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172368: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x172368u;
    {
        const bool branch_taken_0x172368 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17236Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172368u;
            // 0x17236c: 0x34a50145  ori         $a1, $a1, 0x145 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)325);
        ctx->in_delay_slot = false;
        if (branch_taken_0x172368) {
            ctx->pc = 0x172388u;
            goto label_172388;
        }
    }
    ctx->pc = 0x172370u;
    // 0x172370: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172370u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x172374: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x172374u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172378: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172378u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17237c: 0x805a704  j           func_169C10
    ctx->pc = 0x17237Cu;
    ctx->pc = 0x172380u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17237Cu;
            // 0x172380: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x172384u;
    // 0x172384: 0x0  nop
    ctx->pc = 0x172384u;
    // NOP
label_172388:
    // 0x172388: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x172388u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17238c: 0xc05d518  jal         func_175460
    ctx->pc = 0x17238Cu;
    SET_GPR_U32(ctx, 31, 0x172394u);
    ctx->pc = 0x172390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17238Cu;
            // 0x172390: 0x2405001e  addiu       $a1, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172394u; }
        if (ctx->pc != 0x172394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172394u; }
        if (ctx->pc != 0x172394u) { return; }
    }
    ctx->pc = 0x172394u;
label_172394:
    // 0x172394: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x172394u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172398: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172398u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17239c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17239cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1723a0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1723a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1723a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1723A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1723A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1723A4u;
            // 0x1723a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17235Cu: goto label_17235c;
            case 0x172388u: goto label_172388;
            case 0x172394u: goto label_172394;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1723ACu;
    // 0x1723ac: 0x0  nop
    ctx->pc = 0x1723acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
