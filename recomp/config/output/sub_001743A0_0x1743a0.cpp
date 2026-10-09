#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001743A0
// Address: 0x1743a0 - 0x174448
void sub_001743A0_0x1743a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001743A0_0x1743a0");
#endif

    switch (ctx->pc) {
        case 0x1743d0u: goto label_1743d0;
        default: break;
    }

    ctx->pc = 0x1743a0u;

    // 0x1743a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1743a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1743a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1743a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1743a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1743a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1743ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1743acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1743b0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1743b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1743b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1743b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1743b8: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x1743b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1743bc: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1743bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1743c0: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1743C0u;
    {
        const bool branch_taken_0x1743c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1743C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1743C0u;
            // 0x1743c4: 0x100382d  daddu       $a3, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1743c0) {
            ctx->pc = 0x174434u;
            goto label_174434;
        }
    }
    ctx->pc = 0x1743C8u;
    // 0x1743c8: 0xc05d112  jal         func_174448
    ctx->pc = 0x1743C8u;
    SET_GPR_U32(ctx, 31, 0x1743D0u);
    ctx->pc = 0x174448u;
    if (runtime->hasFunction(0x174448u)) {
        auto targetFn = runtime->lookupFunction(0x174448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1743D0u; }
        if (ctx->pc != 0x1743D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174448_0x174448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1743D0u; }
        if (ctx->pc != 0x1743D0u) { return; }
    }
    ctx->pc = 0x1743D0u;
label_1743d0:
    // 0x1743d0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1743d0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1743d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1743d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1743d8: 0x50c20017  beql        $a2, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1743D8u;
    {
        const bool branch_taken_0x1743d8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        if (branch_taken_0x1743d8) {
            ctx->pc = 0x1743DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1743D8u;
            // 0x1743dc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x174438u;
            goto label_174438;
        }
    }
    ctx->pc = 0x1743E0u;
    // 0x1743e0: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1743e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1743e4: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1743e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1743e8: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1743e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1743ec: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x1743ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1743f0: 0x622823  subu        $a1, $v1, $v0
    ctx->pc = 0x1743f0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1743f4: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1743f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1743f8: 0xa2180a  movz        $v1, $a1, $v0
    ctx->pc = 0x1743f8u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 5));
    // 0x1743fc: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1743fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x174400: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x174400u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x174404: 0x862023  subu        $a0, $a0, $a2
    ctx->pc = 0x174404u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x174408: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x174408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17440c: 0xae040008  sw          $a0, 0x8($s0)
    ctx->pc = 0x17440cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 4));
    // 0x174410: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x174410u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x174414: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x174414u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x174418: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x174418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17441c: 0x68430007  ldl         $v1, 0x7($v0)
    ctx->pc = 0x17441cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x174420: 0x6c430000  ldr         $v1, 0x0($v0)
    ctx->pc = 0x174420u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x174424: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x174424u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x174428: 0xb2230007  sdl         $v1, 0x7($s1)
    ctx->pc = 0x174428u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17442c: 0xb6230000  sdr         $v1, 0x0($s1)
    ctx->pc = 0x17442cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x174430: 0xae240008  sw          $a0, 0x8($s1)
    ctx->pc = 0x174430u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 4));
label_174434:
    // 0x174434: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174434u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_174438:
    // 0x174438: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174438u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17443c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17443cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174440: 0x3e00008  jr          $ra
    ctx->pc = 0x174440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174440u;
            // 0x174444: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1743D0u: goto label_1743d0;
            case 0x174434u: goto label_174434;
            case 0x174438u: goto label_174438;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
