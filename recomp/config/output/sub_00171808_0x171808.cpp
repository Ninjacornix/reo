#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171808
// Address: 0x171808 - 0x171880
void sub_00171808_0x171808(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171808_0x171808");
#endif

    switch (ctx->pc) {
        case 0x17186cu: goto label_17186c;
        default: break;
    }

    ctx->pc = 0x171808u;

    // 0x171808: 0x8c831b30  lw          $v1, 0x1B30($a0)
    ctx->pc = 0x171808u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x17180c: 0x3e00008  jr          $ra
    ctx->pc = 0x17180Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17180Cu;
            // 0x171810: 0x8c620aac  lw          $v0, 0xAAC($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 2732)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17186Cu: goto label_17186c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171814u;
    // 0x171814: 0x0  nop
    ctx->pc = 0x171814u;
    // NOP
    // 0x171818: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x171818u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x17181c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17181cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x171820: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x171820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171824: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x171824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x171828: 0xac626120  sw          $v0, 0x6120($v1)
    ctx->pc = 0x171828u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24864), GPR_U32(ctx, 2));
    // 0x17182c: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x17182cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x171830: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x171830u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171834: 0x24486128  addiu       $t0, $v0, 0x6128
    ctx->pc = 0x171834u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 24872));
    // 0x171838: 0x68e30007  ldl         $v1, 0x7($a3)
    ctx->pc = 0x171838u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x17183c: 0x6ce30000  ldr         $v1, 0x0($a3)
    ctx->pc = 0x17183cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x171840: 0xb1030007  sdl         $v1, 0x7($t0)
    ctx->pc = 0x171840u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x171844: 0xb5030000  sdr         $v1, 0x0($t0)
    ctx->pc = 0x171844u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x171848: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x171848u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x17184c: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x17184cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171850: 0x8cc21b30  lw          $v0, 0x1B30($a2)
    ctx->pc = 0x171850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 6960)));
    // 0x171854: 0x68e90007  ldl         $t1, 0x7($a3)
    ctx->pc = 0x171854u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x171858: 0x6ce90000  ldr         $t1, 0x0($a3)
    ctx->pc = 0x171858u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x17185c: 0xb0490aaf  sdl         $t1, 0xAAF($v0)
    ctx->pc = 0x17185cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 2735); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x171860: 0xb4490aa8  sdr         $t1, 0xAA8($v0)
    ctx->pc = 0x171860u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 2728); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x171864: 0xc05a704  jal         func_169C10
    ctx->pc = 0x171864u;
    SET_GPR_U32(ctx, 31, 0x17186Cu);
    ctx->pc = 0x171868u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171864u;
            // 0x171868: 0x34a50f40  ori         $a1, $a1, 0xF40 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3904);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17186Cu; }
        if (ctx->pc != 0x17186Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17186Cu; }
        if (ctx->pc != 0x17186Cu) { return; }
    }
    ctx->pc = 0x17186Cu;
label_17186c:
    // 0x17186c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17186cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171870: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x171870u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171874: 0x3e00008  jr          $ra
    ctx->pc = 0x171874u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171874u;
            // 0x171878: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17186Cu: goto label_17186c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17187Cu;
    // 0x17187c: 0x0  nop
    ctx->pc = 0x17187cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
