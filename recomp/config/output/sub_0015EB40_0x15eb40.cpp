#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EB40
// Address: 0x15eb40 - 0x15ebe8
void sub_0015EB40_0x15eb40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EB40_0x15eb40");
#endif

    switch (ctx->pc) {
        case 0x15eb74u: goto label_15eb74;
        case 0x15eb8cu: goto label_15eb8c;
        case 0x15eba0u: goto label_15eba0;
        case 0x15ebb0u: goto label_15ebb0;
        case 0x15ebc8u: goto label_15ebc8;
        case 0x15ebd8u: goto label_15ebd8;
        default: break;
    }

    ctx->pc = 0x15eb40u;

    // 0x15eb40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15eb40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15eb44: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x15eb44u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x15eb48: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15eb48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15eb4c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15eb4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15eb50: 0x2448ee58  addiu       $t0, $v0, -0x11A8
    ctx->pc = 0x15eb50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962776));
    // 0x15eb54: 0x69050007  ldl         $a1, 0x7($t0)
    ctx->pc = 0x15eb54u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x15eb58: 0x6d050000  ldr         $a1, 0x0($t0)
    ctx->pc = 0x15eb58u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x15eb5c: 0xb3a50007  sdl         $a1, 0x7($sp)
    ctx->pc = 0x15eb5cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15eb60: 0xb7a50000  sdr         $a1, 0x0($sp)
    ctx->pc = 0x15eb60u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15eb64: 0x24052b80  addiu       $a1, $zero, 0x2B80
    ctx->pc = 0x15eb64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11136));
    // 0x15eb68: 0xafa40004  sw          $a0, 0x4($sp)
    ctx->pc = 0x15eb68u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 4));
    // 0x15eb6c: 0xc05a67c  jal         func_1699F0
    ctx->pc = 0x15EB6Cu;
    SET_GPR_U32(ctx, 31, 0x15EB74u);
    ctx->pc = 0x15EB70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EB6Cu;
            // 0x15eb70: 0x2464eed8  addiu       $a0, $v1, -0x1128 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294962904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1699F0u;
    if (runtime->hasFunction(0x1699F0u)) {
        auto targetFn = runtime->lookupFunction(0x1699F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EB74u; }
        if (ctx->pc != 0x15EB74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001699F0_0x1699f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EB74u; }
        if (ctx->pc != 0x15EB74u) { return; }
    }
    ctx->pc = 0x15EB74u;
label_15eb74:
    // 0x15eb74: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15eb74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15eb78: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15EB78u;
    {
        const bool branch_taken_0x15eb78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x15EB7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EB78u;
            // 0x15eb7c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15eb78) {
            ctx->pc = 0x15EB98u;
            goto label_15eb98;
        }
    }
    ctx->pc = 0x15EB80u;
    // 0x15eb80: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15eb80u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15eb84: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15EB84u;
    SET_GPR_U32(ctx, 31, 0x15EB8Cu);
    ctx->pc = 0x15EB88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EB84u;
            // 0x15eb88: 0x2484eee0  addiu       $a0, $a0, -0x1120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962912));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EB8Cu; }
        if (ctx->pc != 0x15EB8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EB8Cu; }
        if (ctx->pc != 0x15EB8Cu) { return; }
    }
    ctx->pc = 0x15EB8Cu;
label_15eb8c:
    // 0x15eb8c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x15EB8Cu;
    {
        const bool branch_taken_0x15eb8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EB8Cu;
            // 0x15eb90: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15eb8c) {
            ctx->pc = 0x15EBD8u;
            goto label_15ebd8;
        }
    }
    ctx->pc = 0x15EB94u;
    // 0x15eb94: 0x0  nop
    ctx->pc = 0x15eb94u;
    // NOP
label_15eb98:
    // 0x15eb98: 0xc05a680  jal         func_169A00
    ctx->pc = 0x15EB98u;
    SET_GPR_U32(ctx, 31, 0x15EBA0u);
    ctx->pc = 0x169A00u;
    if (runtime->hasFunction(0x169A00u)) {
        auto targetFn = runtime->lookupFunction(0x169A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBA0u; }
        if (ctx->pc != 0x15EBA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169A00_0x169a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBA0u; }
        if (ctx->pc != 0x15EBA0u) { return; }
    }
    ctx->pc = 0x15EBA0u;
label_15eba0:
    // 0x15eba0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15EBA0u;
    {
        const bool branch_taken_0x15eba0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EBA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EBA0u;
            // 0x15eba4: 0x3c050016  lui         $a1, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15eba0) {
            ctx->pc = 0x15EBB8u;
            goto label_15ebb8;
        }
    }
    ctx->pc = 0x15EBA8u;
    // 0x15eba8: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15EBA8u;
    SET_GPR_U32(ctx, 31, 0x15EBB0u);
    ctx->pc = 0x15EBACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EBA8u;
            // 0x15ebac: 0x2404fed3  addiu       $a0, $zero, -0x12D (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966995));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBB0u; }
        if (ctx->pc != 0x15EBB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBB0u; }
        if (ctx->pc != 0x15EBB0u) { return; }
    }
    ctx->pc = 0x15EBB0u;
label_15ebb0:
    // 0x15ebb0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x15EBB0u;
    {
        const bool branch_taken_0x15ebb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EBB0u;
            // 0x15ebb4: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ebb0) {
            ctx->pc = 0x15EBDCu;
            goto label_15ebdc;
        }
    }
    ctx->pc = 0x15EBB8u;
label_15ebb8:
    // 0x15ebb8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15ebb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ebbc: 0x24a5ec08  addiu       $a1, $a1, -0x13F8
    ctx->pc = 0x15ebbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962184));
    // 0x15ebc0: 0xc05a730  jal         func_169CC0
    ctx->pc = 0x15EBC0u;
    SET_GPR_U32(ctx, 31, 0x15EBC8u);
    ctx->pc = 0x15EBC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EBC0u;
            // 0x15ebc4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169CC0u;
    if (runtime->hasFunction(0x169CC0u)) {
        auto targetFn = runtime->lookupFunction(0x169CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBC8u; }
        if (ctx->pc != 0x15EBC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169CC0_0x169cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBC8u; }
        if (ctx->pc != 0x15EBC8u) { return; }
    }
    ctx->pc = 0x15EBC8u;
label_15ebc8:
    // 0x15ebc8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15EBC8u;
    {
        const bool branch_taken_0x15ebc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15EBCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EBC8u;
            // 0x15ebcc: 0x2404fed1  addiu       $a0, $zero, -0x12F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966993));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ebc8) {
            ctx->pc = 0x15EBD8u;
            goto label_15ebd8;
        }
    }
    ctx->pc = 0x15EBD0u;
    // 0x15ebd0: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15EBD0u;
    SET_GPR_U32(ctx, 31, 0x15EBD8u);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBD8u; }
        if (ctx->pc != 0x15EBD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EBD8u; }
        if (ctx->pc != 0x15EBD8u) { return; }
    }
    ctx->pc = 0x15EBD8u;
label_15ebd8:
    // 0x15ebd8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15ebd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_15ebdc:
    // 0x15ebdc: 0x3e00008  jr          $ra
    ctx->pc = 0x15EBDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EBE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EBDCu;
            // 0x15ebe0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EB74u: goto label_15eb74;
            case 0x15EB8Cu: goto label_15eb8c;
            case 0x15EB98u: goto label_15eb98;
            case 0x15EBA0u: goto label_15eba0;
            case 0x15EBB0u: goto label_15ebb0;
            case 0x15EBB8u: goto label_15ebb8;
            case 0x15EBC8u: goto label_15ebc8;
            case 0x15EBD8u: goto label_15ebd8;
            case 0x15EBDCu: goto label_15ebdc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EBE4u;
    // 0x15ebe4: 0x0  nop
    ctx->pc = 0x15ebe4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
