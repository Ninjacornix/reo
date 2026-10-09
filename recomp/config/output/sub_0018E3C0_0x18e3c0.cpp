#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E3C0
// Address: 0x18e3c0 - 0x18e480
void sub_0018E3C0_0x18e3c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E3C0_0x18e3c0");
#endif

    switch (ctx->pc) {
        case 0x18e418u: goto label_18e418;
        case 0x18e428u: goto label_18e428;
        case 0x18e438u: goto label_18e438;
        case 0x18e448u: goto label_18e448;
        case 0x18e458u: goto label_18e458;
        case 0x18e468u: goto label_18e468;
        default: break;
    }

    ctx->pc = 0x18e3c0u;

    // 0x18e3c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x18e3c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18e3c4: 0x24020013  addiu       $v0, $zero, 0x13
    ctx->pc = 0x18e3c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x18e3c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x18e3c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x18e3cc: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x18e3ccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18e3d0: 0x10620023  beq         $v1, $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x18E3D0u;
    {
        const bool branch_taken_0x18e3d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18E3D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E3D0u;
            // 0x18e3d4: 0x24020012  addiu       $v0, $zero, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e3d0) {
            ctx->pc = 0x18E460u;
            goto label_18e460;
        }
    }
    ctx->pc = 0x18E3D8u;
    // 0x18e3d8: 0x1062001d  beq         $v1, $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x18E3D8u;
    {
        const bool branch_taken_0x18e3d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18e3d8) {
            ctx->pc = 0x18E450u;
            goto label_18e450;
        }
    }
    ctx->pc = 0x18E3E0u;
    // 0x18e3e0: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x18e3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x18e3e4: 0x10620016  beq         $v1, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x18E3E4u;
    {
        const bool branch_taken_0x18e3e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18E3E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E3E4u;
            // 0x18e3e8: 0x24020023  addiu       $v0, $zero, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e3e4) {
            ctx->pc = 0x18E440u;
            goto label_18e440;
        }
    }
    ctx->pc = 0x18E3ECu;
    // 0x18e3ec: 0x10620010  beq         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x18E3ECu;
    {
        const bool branch_taken_0x18e3ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18e3ec) {
            ctx->pc = 0x18E430u;
            goto label_18e430;
        }
    }
    ctx->pc = 0x18E3F4u;
    // 0x18e3f4: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x18e3f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x18e3f8: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x18E3F8u;
    {
        const bool branch_taken_0x18e3f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18E3FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E3F8u;
            // 0x18e3fc: 0x24020021  addiu       $v0, $zero, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e3f8) {
            ctx->pc = 0x18E420u;
            goto label_18e420;
        }
    }
    ctx->pc = 0x18E400u;
    // 0x18e400: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18E400u;
    {
        const bool branch_taken_0x18e400 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18e400) {
            ctx->pc = 0x18E410u;
            goto label_18e410;
        }
    }
    ctx->pc = 0x18E408u;
    // 0x18e408: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x18E408u;
    {
        const bool branch_taken_0x18e408 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E40Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E408u;
            // 0x18e40c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e408) {
            ctx->pc = 0x18E46Cu;
            goto label_18e46c;
        }
    }
    ctx->pc = 0x18E410u;
label_18e410:
    // 0x18e410: 0xc063920  jal         func_18E480
    ctx->pc = 0x18E410u;
    SET_GPR_U32(ctx, 31, 0x18E418u);
    ctx->pc = 0x18E480u;
    if (runtime->hasFunction(0x18E480u)) {
        auto targetFn = runtime->lookupFunction(0x18E480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E418u; }
        if (ctx->pc != 0x18E418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E480_0x18e480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E418u; }
        if (ctx->pc != 0x18E418u) { return; }
    }
    ctx->pc = 0x18E418u;
label_18e418:
    // 0x18e418: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x18E418u;
    {
        const bool branch_taken_0x18e418 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e418) {
            ctx->pc = 0x18E468u;
            goto label_18e468;
        }
    }
    ctx->pc = 0x18E420u;
label_18e420:
    // 0x18e420: 0xc063940  jal         func_18E500
    ctx->pc = 0x18E420u;
    SET_GPR_U32(ctx, 31, 0x18E428u);
    ctx->pc = 0x18E500u;
    if (runtime->hasFunction(0x18E500u)) {
        auto targetFn = runtime->lookupFunction(0x18E500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E428u; }
        if (ctx->pc != 0x18E428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E500_0x18e500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E428u; }
        if (ctx->pc != 0x18E428u) { return; }
    }
    ctx->pc = 0x18E428u;
label_18e428:
    // 0x18e428: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x18E428u;
    {
        const bool branch_taken_0x18e428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e428) {
            ctx->pc = 0x18E468u;
            goto label_18e468;
        }
    }
    ctx->pc = 0x18E430u;
label_18e430:
    // 0x18e430: 0xc063964  jal         func_18E590
    ctx->pc = 0x18E430u;
    SET_GPR_U32(ctx, 31, 0x18E438u);
    ctx->pc = 0x18E590u;
    if (runtime->hasFunction(0x18E590u)) {
        auto targetFn = runtime->lookupFunction(0x18E590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E438u; }
        if (ctx->pc != 0x18E438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E590_0x18e590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E438u; }
        if (ctx->pc != 0x18E438u) { return; }
    }
    ctx->pc = 0x18E438u;
label_18e438:
    // 0x18e438: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x18E438u;
    {
        const bool branch_taken_0x18e438 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e438) {
            ctx->pc = 0x18E468u;
            goto label_18e468;
        }
    }
    ctx->pc = 0x18E440u;
label_18e440:
    // 0x18e440: 0xc063998  jal         func_18E660
    ctx->pc = 0x18E440u;
    SET_GPR_U32(ctx, 31, 0x18E448u);
    ctx->pc = 0x18E660u;
    if (runtime->hasFunction(0x18E660u)) {
        auto targetFn = runtime->lookupFunction(0x18E660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E448u; }
        if (ctx->pc != 0x18E448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E660_0x18e660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E448u; }
        if (ctx->pc != 0x18E448u) { return; }
    }
    ctx->pc = 0x18E448u;
label_18e448:
    // 0x18e448: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18E448u;
    {
        const bool branch_taken_0x18e448 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e448) {
            ctx->pc = 0x18E468u;
            goto label_18e468;
        }
    }
    ctx->pc = 0x18E450u;
label_18e450:
    // 0x18e450: 0xc0639c4  jal         func_18E710
    ctx->pc = 0x18E450u;
    SET_GPR_U32(ctx, 31, 0x18E458u);
    ctx->pc = 0x18E710u;
    if (runtime->hasFunction(0x18E710u)) {
        auto targetFn = runtime->lookupFunction(0x18E710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E458u; }
        if (ctx->pc != 0x18E458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E710_0x18e710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E458u; }
        if (ctx->pc != 0x18E458u) { return; }
    }
    ctx->pc = 0x18E458u;
label_18e458:
    // 0x18e458: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18E458u;
    {
        const bool branch_taken_0x18e458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18e458) {
            ctx->pc = 0x18E468u;
            goto label_18e468;
        }
    }
    ctx->pc = 0x18E460u;
label_18e460:
    // 0x18e460: 0xc0639f4  jal         func_18E7D0
    ctx->pc = 0x18E460u;
    SET_GPR_U32(ctx, 31, 0x18E468u);
    ctx->pc = 0x18E7D0u;
    if (runtime->hasFunction(0x18E7D0u)) {
        auto targetFn = runtime->lookupFunction(0x18E7D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E468u; }
        if (ctx->pc != 0x18E468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E7D0_0x18e7d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E468u; }
        if (ctx->pc != 0x18E468u) { return; }
    }
    ctx->pc = 0x18E468u;
label_18e468:
    // 0x18e468: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x18e468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_18e46c:
    // 0x18e46c: 0x3e00008  jr          $ra
    ctx->pc = 0x18E46Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18E470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E46Cu;
            // 0x18e470: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18E410u: goto label_18e410;
            case 0x18E418u: goto label_18e418;
            case 0x18E420u: goto label_18e420;
            case 0x18E428u: goto label_18e428;
            case 0x18E430u: goto label_18e430;
            case 0x18E438u: goto label_18e438;
            case 0x18E440u: goto label_18e440;
            case 0x18E448u: goto label_18e448;
            case 0x18E450u: goto label_18e450;
            case 0x18E458u: goto label_18e458;
            case 0x18E460u: goto label_18e460;
            case 0x18E468u: goto label_18e468;
            case 0x18E46Cu: goto label_18e46c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18E474u;
    // 0x18e474: 0x0  nop
    ctx->pc = 0x18e474u;
    // NOP
    // 0x18e478: 0x0  nop
    ctx->pc = 0x18e478u;
    // NOP
    // 0x18e47c: 0x0  nop
    ctx->pc = 0x18e47cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
