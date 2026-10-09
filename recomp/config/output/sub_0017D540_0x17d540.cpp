#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D540
// Address: 0x17d540 - 0x17d5c8
void sub_0017D540_0x17d540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D540_0x17d540");
#endif

    switch (ctx->pc) {
        case 0x17d590u: goto label_17d590;
        case 0x17d5a0u: goto label_17d5a0;
        default: break;
    }

    ctx->pc = 0x17d540u;

    // 0x17d540: 0x617c2  srl         $v0, $a2, 31
    ctx->pc = 0x17d540u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 31));
    // 0x17d544: 0x51fc2  srl         $v1, $a1, 31
    ctx->pc = 0x17d544u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 31));
    // 0x17d548: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x17d548u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x17d54c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x17d54cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x17d550: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17d550u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17d554: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17d554u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17d558: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x17d558u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x17d55c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x17d55cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x17d560: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x17d560u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x17d564: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d568: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17d568u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d56c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17d56cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17d570: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17d570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17d574: 0x39043  sra         $s2, $v1, 1
    ctx->pc = 0x17d574u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 3), 1));
    // 0x17d578: 0x28843  sra         $s1, $v0, 1
    ctx->pc = 0x17d578u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17d57c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x17d57cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d580: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x17d580u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d584: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17d584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17d588: 0xc05f572  jal         func_17D5C8
    ctx->pc = 0x17D588u;
    SET_GPR_U32(ctx, 31, 0x17D590u);
    ctx->pc = 0x17D58Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D588u;
            // 0x17d58c: 0x26040004  addiu       $a0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D5C8u;
    if (runtime->hasFunction(0x17D5C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D5C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D590u; }
        if (ctx->pc != 0x17D590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D5C8_0x17d5c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D590u; }
        if (ctx->pc != 0x17D590u) { return; }
    }
    ctx->pc = 0x17D590u;
label_17d590:
    // 0x17d590: 0x26040014  addiu       $a0, $s0, 0x14
    ctx->pc = 0x17d590u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17d594: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17d594u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d598: 0xc05f572  jal         func_17D5C8
    ctx->pc = 0x17D598u;
    SET_GPR_U32(ctx, 31, 0x17D5A0u);
    ctx->pc = 0x17D59Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D598u;
            // 0x17d59c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D5C8u;
    if (runtime->hasFunction(0x17D5C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D5C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D5A0u; }
        if (ctx->pc != 0x17D5A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D5C8_0x17d5c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D5A0u; }
        if (ctx->pc != 0x17D5A0u) { return; }
    }
    ctx->pc = 0x17D5A0u;
label_17d5a0:
    // 0x17d5a0: 0x26040024  addiu       $a0, $s0, 0x24
    ctx->pc = 0x17d5a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x17d5a4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17d5a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d5a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17d5a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d5ac: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17d5acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d5b0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17d5b0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17d5b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d5b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d5b8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17d5b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17d5bc: 0x805f572  j           func_17D5C8
    ctx->pc = 0x17D5BCu;
    ctx->pc = 0x17D5C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D5BCu;
            // 0x17d5c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D5C8u;
    if (runtime->hasFunction(0x17D5C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D5C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D5C8_0x17d5c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D5C4u;
    // 0x17d5c4: 0x0  nop
    ctx->pc = 0x17d5c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
