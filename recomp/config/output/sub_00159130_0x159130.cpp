#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159130
// Address: 0x159130 - 0x1591e8
void sub_00159130_0x159130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159130_0x159130");
#endif

    switch (ctx->pc) {
        case 0x159154u: goto label_159154;
        case 0x159190u: goto label_159190;
        case 0x159198u: goto label_159198;
        case 0x1591bcu: goto label_1591bc;
        default: break;
    }

    ctx->pc = 0x159130u;

    // 0x159130: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x159130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x159134: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x159134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x159138: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x159138u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15913c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15913cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x159140: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x159140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x159144: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x159144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x159148: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x159148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15914c: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x15914Cu;
    SET_GPR_U32(ctx, 31, 0x159154u);
    ctx->pc = 0x159150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15914Cu;
            // 0x159150: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159154u; }
        if (ctx->pc != 0x159154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159154u; }
        if (ctx->pc != 0x159154u) { return; }
    }
    ctx->pc = 0x159154u;
label_159154:
    // 0x159154: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x159154u;
    {
        const bool branch_taken_0x159154 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x159158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159154u;
            // 0x159158: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159154) {
            ctx->pc = 0x159180u;
            goto label_159180;
        }
    }
    ctx->pc = 0x15915Cu;
    // 0x15915c: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15915cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x159160: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x159160u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159164: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x159164u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159168: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x159168u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15916c: 0x34a5020a  ori         $a1, $a1, 0x20A
    ctx->pc = 0x15916cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)522);
    // 0x159170: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x159170u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159174: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x159174u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x159178: 0x80563ce  j           func_158F38
    ctx->pc = 0x159178u;
    ctx->pc = 0x15917Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159178u;
            // 0x15917c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x159180u;
label_159180:
    // 0x159180: 0x3c11ff03  lui         $s1, 0xFF03
    ctx->pc = 0x159180u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)65283 << 16));
    // 0x159184: 0x24120004  addiu       $s2, $zero, 0x4
    ctx->pc = 0x159184u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x159188: 0x36310305  ori         $s1, $s1, 0x305
    ctx->pc = 0x159188u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)773);
    // 0x15918c: 0x0  nop
    ctx->pc = 0x15918cu;
    // NOP
label_159190:
    // 0x159190: 0xc056b7a  jal         func_15ADE8
    ctx->pc = 0x159190u;
    SET_GPR_U32(ctx, 31, 0x159198u);
    ctx->pc = 0x159194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159190u;
            // 0x159194: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15ADE8u;
    if (runtime->hasFunction(0x15ADE8u)) {
        auto targetFn = runtime->lookupFunction(0x15ADE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159198u; }
        if (ctx->pc != 0x159198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015ADE8_0x15ade8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159198u; }
        if (ctx->pc != 0x159198u) { return; }
    }
    ctx->pc = 0x159198u;
label_159198:
    // 0x159198: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x159198u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15919c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15919cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1591a0: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1591a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1591a4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1591A4u;
    {
        const bool branch_taken_0x1591a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1591A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1591A4u;
            // 0x1591a8: 0x304300cc  andi        $v1, $v0, 0xCC (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)204);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1591a4) {
            ctx->pc = 0x1591C4u;
            goto label_1591c4;
        }
    }
    ctx->pc = 0x1591ACu;
    // 0x1591ac: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1591ACu;
    {
        const bool branch_taken_0x1591ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1591ac) {
            ctx->pc = 0x1591B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1591ACu;
            // 0x1591b0: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1591C4u;
            goto label_1591c4;
        }
    }
    ctx->pc = 0x1591B4u;
    // 0x1591b4: 0xc056c04  jal         func_15B010
    ctx->pc = 0x1591B4u;
    SET_GPR_U32(ctx, 31, 0x1591BCu);
    ctx->pc = 0x15B010u;
    if (runtime->hasFunction(0x15B010u)) {
        auto targetFn = runtime->lookupFunction(0x15B010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1591BCu; }
        if (ctx->pc != 0x1591BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B010_0x15b010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1591BCu; }
        if (ctx->pc != 0x1591BCu) { return; }
    }
    ctx->pc = 0x1591BCu;
label_1591bc:
    // 0x1591bc: 0x1052fff4  beq         $v0, $s2, . + 4 + (-0xC << 2)
    ctx->pc = 0x1591BCu;
    {
        const bool branch_taken_0x1591bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        if (branch_taken_0x1591bc) {
            ctx->pc = 0x159190u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_159190;
        }
    }
    ctx->pc = 0x1591C4u;
label_1591c4:
    // 0x1591c4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1591c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1591c8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1591c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1591cc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1591ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1591d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1591d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1591d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1591d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1591d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1591d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1591dc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1591dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1591e0: 0x80563ce  j           func_158F38
    ctx->pc = 0x1591E0u;
    ctx->pc = 0x1591E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1591E0u;
            // 0x1591e4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1591E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
