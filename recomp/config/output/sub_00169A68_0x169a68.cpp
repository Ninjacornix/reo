#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169A68
// Address: 0x169a68 - 0x169b28
void sub_00169A68_0x169a68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169A68_0x169a68");
#endif

    switch (ctx->pc) {
        case 0x169a94u: goto label_169a94;
        case 0x169aa8u: goto label_169aa8;
        case 0x169ac4u: goto label_169ac4;
        case 0x169ad0u: goto label_169ad0;
        case 0x169ad8u: goto label_169ad8;
        case 0x169ae0u: goto label_169ae0;
        case 0x169ae8u: goto label_169ae8;
        case 0x169b14u: goto label_169b14;
        default: break;
    }

    ctx->pc = 0x169a68u;

    // 0x169a68: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x169a68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x169a6c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x169a6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169a70: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169a70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x169a74: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x169a74u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x169a78: 0x2610ef88  addiu       $s0, $s0, -0x1078
    ctx->pc = 0x169a78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963080));
    // 0x169a7c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x169a7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x169a80: 0x24060089  addiu       $a2, $zero, 0x89
    ctx->pc = 0x169a80u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 137));
    // 0x169a84: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x169a84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169a88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x169a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x169a8c: 0xc0558b4  jal         func_1562D0
    ctx->pc = 0x169A8Cu;
    SET_GPR_U32(ctx, 31, 0x169A94u);
    ctx->pc = 0x169A90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169A8Cu;
            // 0x169a90: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1562D0u;
    if (runtime->hasFunction(0x1562D0u)) {
        auto targetFn = runtime->lookupFunction(0x1562D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A94u; }
        if (ctx->pc != 0x169A94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001562D0_0x1562d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169A94u; }
        if (ctx->pc != 0x169A94u) { return; }
    }
    ctx->pc = 0x169A94u;
label_169a94:
    // 0x169a94: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x169a94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x169a98: 0x24060190  addiu       $a2, $zero, 0x190
    ctx->pc = 0x169a98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
    // 0x169a9c: 0x24a50930  addiu       $a1, $a1, 0x930
    ctx->pc = 0x169a9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2352));
    // 0x169aa0: 0xc055798  jal         func_155E60
    ctx->pc = 0x169AA0u;
    SET_GPR_U32(ctx, 31, 0x169AA8u);
    ctx->pc = 0x169AA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169AA0u;
            // 0x169aa4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AA8u; }
        if (ctx->pc != 0x169AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AA8u; }
        if (ctx->pc != 0x169AA8u) { return; }
    }
    ctx->pc = 0x169AA8u;
label_169aa8:
    // 0x169aa8: 0x6a220007  ldl         $v0, 0x7($s1)
    ctx->pc = 0x169aa8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x169aac: 0x6e220000  ldr         $v0, 0x0($s1)
    ctx->pc = 0x169aacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x169ab0: 0xb2020197  sdl         $v0, 0x197($s0)
    ctx->pc = 0x169ab0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 407); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x169ab4: 0xb6020190  sdr         $v0, 0x190($s0)
    ctx->pc = 0x169ab4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 400); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x169ab8: 0xae000198  sw          $zero, 0x198($s0)
    ctx->pc = 0x169ab8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 0));
    // 0x169abc: 0xc05a6f8  jal         func_169BE0
    ctx->pc = 0x169ABCu;
    SET_GPR_U32(ctx, 31, 0x169AC4u);
    ctx->pc = 0x169AC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169ABCu;
            // 0x169ac0: 0x2604019c  addiu       $a0, $s0, 0x19C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 412));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169BE0u;
    if (runtime->hasFunction(0x169BE0u)) {
        auto targetFn = runtime->lookupFunction(0x169BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AC4u; }
        if (ctx->pc != 0x169AC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169BE0_0x169be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AC4u; }
        if (ctx->pc != 0x169AC4u) { return; }
    }
    ctx->pc = 0x169AC4u;
label_169ac4:
    // 0x169ac4: 0x260401b0  addiu       $a0, $s0, 0x1B0
    ctx->pc = 0x169ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 432));
    // 0x169ac8: 0xc05d68e  jal         func_175A38
    ctx->pc = 0x169AC8u;
    SET_GPR_U32(ctx, 31, 0x169AD0u);
    ctx->pc = 0x169ACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169AC8u;
            // 0x169acc: 0x8e250004  lw          $a1, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175A38u;
    if (runtime->hasFunction(0x175A38u)) {
        auto targetFn = runtime->lookupFunction(0x175A38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AD0u; }
        if (ctx->pc != 0x169AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175A38_0x175a38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AD0u; }
        if (ctx->pc != 0x169AD0u) { return; }
    }
    ctx->pc = 0x169AD0u;
label_169ad0:
    // 0x169ad0: 0xc0599c4  jal         func_166710
    ctx->pc = 0x169AD0u;
    SET_GPR_U32(ctx, 31, 0x169AD8u);
    ctx->pc = 0x169AD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169AD0u;
            // 0x169ad4: 0x260401bc  addiu       $a0, $s0, 0x1BC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 444));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166710u;
    if (runtime->hasFunction(0x166710u)) {
        auto targetFn = runtime->lookupFunction(0x166710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AD8u; }
        if (ctx->pc != 0x169AD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166710_0x166710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AD8u; }
        if (ctx->pc != 0x169AD8u) { return; }
    }
    ctx->pc = 0x169AD8u;
label_169ad8:
    // 0x169ad8: 0xc05a6ca  jal         func_169B28
    ctx->pc = 0x169AD8u;
    SET_GPR_U32(ctx, 31, 0x169AE0u);
    ctx->pc = 0x169ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169AD8u;
            // 0x169adc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169B28u;
    if (runtime->hasFunction(0x169B28u)) {
        auto targetFn = runtime->lookupFunction(0x169B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AE0u; }
        if (ctx->pc != 0x169AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169B28_0x169b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169AE0u; }
        if (ctx->pc != 0x169AE0u) { return; }
    }
    ctx->pc = 0x169AE0u;
label_169ae0:
    // 0x169ae0: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x169ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x169ae4: 0x26100220  addiu       $s0, $s0, 0x220
    ctx->pc = 0x169ae4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 544));
label_169ae8:
    // 0x169ae8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x169ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x169aec: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x169aecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x169af0: 0x0  nop
    ctx->pc = 0x169af0u;
    // NOP
    // 0x169af4: 0x0  nop
    ctx->pc = 0x169af4u;
    // NOP
    // 0x169af8: 0x0  nop
    ctx->pc = 0x169af8u;
    // NOP
    // 0x169afc: 0x441fffa  bgez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x169AFCu;
    {
        const bool branch_taken_0x169afc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x169B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169AFCu;
            // 0x169b00: 0x2610fffc  addiu       $s0, $s0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169afc) {
            ctx->pc = 0x169AE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_169ae8;
        }
    }
    ctx->pc = 0x169B04u;
    // 0x169b04: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x169b04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x169b08: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x169b08u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x169b0c: 0xc05dd2c  jal         func_1774B0
    ctx->pc = 0x169B0Cu;
    SET_GPR_U32(ctx, 31, 0x169B14u);
    ctx->pc = 0x169B10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169B0Cu;
            // 0x169b10: 0x2484f148  addiu       $a0, $a0, -0xEB8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1774B0u;
    if (runtime->hasFunction(0x1774B0u)) {
        auto targetFn = runtime->lookupFunction(0x1774B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169B14u; }
        if (ctx->pc != 0x169B14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001774B0_0x1774b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169B14u; }
        if (ctx->pc != 0x169B14u) { return; }
    }
    ctx->pc = 0x169B14u;
label_169b14:
    // 0x169b14: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169b14u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169b18: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x169b18u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169b1c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x169b1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169b20: 0x3e00008  jr          $ra
    ctx->pc = 0x169B20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169B20u;
            // 0x169b24: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169A94u: goto label_169a94;
            case 0x169AA8u: goto label_169aa8;
            case 0x169AC4u: goto label_169ac4;
            case 0x169AD0u: goto label_169ad0;
            case 0x169AD8u: goto label_169ad8;
            case 0x169AE0u: goto label_169ae0;
            case 0x169AE8u: goto label_169ae8;
            case 0x169B14u: goto label_169b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169B28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
