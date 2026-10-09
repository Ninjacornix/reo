#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174118
// Address: 0x174118 - 0x1741a0
void sub_00174118_0x174118(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174118_0x174118");
#endif

    switch (ctx->pc) {
        case 0x17414cu: goto label_17414c;
        case 0x174184u: goto label_174184;
        default: break;
    }

    ctx->pc = 0x174118u;

    // 0x174118: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174118u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17411c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17411cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174120: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x174120u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174124: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174128: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x174128u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17412c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17412cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x174130: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x174130u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174134: 0x12200013  beqz        $s1, . + 4 + (0x13 << 2)
    ctx->pc = 0x174134u;
    {
        const bool branch_taken_0x174134 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x174138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174134u;
            // 0x174138: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174134) {
            ctx->pc = 0x174184u;
            goto label_174184;
        }
    }
    ctx->pc = 0x17413Cu;
    // 0x17413c: 0x1a000012  blez        $s0, . + 4 + (0x12 << 2)
    ctx->pc = 0x17413Cu;
    {
        const bool branch_taken_0x17413c = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x174140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17413Cu;
            // 0x174140: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17413c) {
            ctx->pc = 0x174188u;
            goto label_174188;
        }
    }
    ctx->pc = 0x174144u;
    // 0x174144: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174144u;
    SET_GPR_U32(ctx, 31, 0x17414Cu);
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17414Cu; }
        if (ctx->pc != 0x17414Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17414Cu; }
        if (ctx->pc != 0x17414Cu) { return; }
    }
    ctx->pc = 0x17414Cu;
label_17414c:
    // 0x17414c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17414cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174150: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x174150u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174154: 0x34a50165  ori         $a1, $a1, 0x165
    ctx->pc = 0x174154u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)357);
    // 0x174158: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x174158u;
    {
        const bool branch_taken_0x174158 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17415Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174158u;
            // 0x17415c: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174158) {
            ctx->pc = 0x174178u;
            goto label_174178;
        }
    }
    ctx->pc = 0x174160u;
    // 0x174160: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174160u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174164: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174164u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174168: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x174168u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17416c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17416cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174170: 0x805a704  j           func_169C10
    ctx->pc = 0x174170u;
    ctx->pc = 0x174174u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174170u;
            // 0x174174: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x174178u;
label_174178:
    // 0x174178: 0x264411ec  addiu       $a0, $s2, 0x11EC
    ctx->pc = 0x174178u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 4588));
    // 0x17417c: 0xc05d068  jal         func_1741A0
    ctx->pc = 0x17417Cu;
    SET_GPR_U32(ctx, 31, 0x174184u);
    ctx->pc = 0x174180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17417Cu;
            // 0x174180: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1741A0u;
    if (runtime->hasFunction(0x1741A0u)) {
        auto targetFn = runtime->lookupFunction(0x1741A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174184u; }
        if (ctx->pc != 0x174184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001741A0_0x1741a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174184u; }
        if (ctx->pc != 0x174184u) { return; }
    }
    ctx->pc = 0x174184u;
label_174184:
    // 0x174184: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174184u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_174188:
    // 0x174188: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174188u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17418c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17418cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174190: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x174190u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174194: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x174194u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174198: 0x3e00008  jr          $ra
    ctx->pc = 0x174198u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17419Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174198u;
            // 0x17419c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17414Cu: goto label_17414c;
            case 0x174178u: goto label_174178;
            case 0x174184u: goto label_174184;
            case 0x174188u: goto label_174188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1741A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
