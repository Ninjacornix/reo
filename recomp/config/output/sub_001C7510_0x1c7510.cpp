#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7510
// Address: 0x1c7510 - 0x1c76e0
void sub_001C7510_0x1c7510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7510_0x1c7510");
#endif

    switch (ctx->pc) {
        case 0x1c753cu: goto label_1c753c;
        case 0x1c7550u: goto label_1c7550;
        case 0x1c759cu: goto label_1c759c;
        case 0x1c75b8u: goto label_1c75b8;
        case 0x1c75c4u: goto label_1c75c4;
        case 0x1c75d0u: goto label_1c75d0;
        case 0x1c75e8u: goto label_1c75e8;
        default: break;
    }

    ctx->pc = 0x1c7510u;

    // 0x1c7510: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c7510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c7514: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7514u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7518: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c7518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c751c: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1c751cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1c7520: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c7520u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c7524: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7524u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7528: 0x90245056  lbu         $a0, 0x5056($at)
    ctx->pc = 0x1c7528u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20566)));
    // 0x1c752c: 0x10830065  beq         $a0, $v1, . + 4 + (0x65 << 2)
    ctx->pc = 0x1C752Cu;
    {
        const bool branch_taken_0x1c752c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c752c) {
            ctx->pc = 0x1C76C4u;
            goto label_1c76c4;
        }
    }
    ctx->pc = 0x1C7534u;
    // 0x1c7534: 0xc071cbc  jal         func_1C72F0
    ctx->pc = 0x1C7534u;
    SET_GPR_U32(ctx, 31, 0x1C753Cu);
    ctx->pc = 0x1C72F0u;
    if (runtime->hasFunction(0x1C72F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C72F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C753Cu; }
        if (ctx->pc != 0x1C753Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C72F0_0x1c72f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C753Cu; }
        if (ctx->pc != 0x1C753Cu) { return; }
    }
    ctx->pc = 0x1C753Cu;
label_1c753c:
    // 0x1c753c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c753cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c7540: 0x10430060  beq         $v0, $v1, . + 4 + (0x60 << 2)
    ctx->pc = 0x1C7540u;
    {
        const bool branch_taken_0x1c7540 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C7544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7540u;
            // 0x1c7544: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7540) {
            ctx->pc = 0x1C76C4u;
            goto label_1c76c4;
        }
    }
    ctx->pc = 0x1C7548u;
    // 0x1c7548: 0xc071d00  jal         func_1C7400
    ctx->pc = 0x1C7548u;
    SET_GPR_U32(ctx, 31, 0x1C7550u);
    ctx->pc = 0x1C7400u;
    if (runtime->hasFunction(0x1C7400u)) {
        auto targetFn = runtime->lookupFunction(0x1C7400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7550u; }
        if (ctx->pc != 0x1C7550u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7400_0x1c7400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7550u; }
        if (ctx->pc != 0x1C7550u) { return; }
    }
    ctx->pc = 0x1C7550u;
label_1c7550:
    // 0x1c7550: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c7550u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c7554: 0x1043005b  beq         $v0, $v1, . + 4 + (0x5B << 2)
    ctx->pc = 0x1C7554u;
    {
        const bool branch_taken_0x1c7554 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C7558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7554u;
            // 0x1c7558: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7554) {
            ctx->pc = 0x1C76C4u;
            goto label_1c76c4;
        }
    }
    ctx->pc = 0x1C755Cu;
    // 0x1c755c: 0x2111821  addu        $v1, $s0, $s1
    ctx->pc = 0x1c755cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1c7560: 0x14600034  bnez        $v1, . + 4 + (0x34 << 2)
    ctx->pc = 0x1C7560u;
    {
        const bool branch_taken_0x1c7560 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7560u;
            // 0x1c7564: 0x2113021  addu        $a2, $s0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7560) {
            ctx->pc = 0x1C7634u;
            goto label_1c7634;
        }
    }
    ctx->pc = 0x1C7568u;
    // 0x1c7568: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7568u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c756c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1c756cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1c7570: 0xc422506c  lwc1        $f2, 0x506C($at)
    ctx->pc = 0x1c7570u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20588)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1c7574: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1c7574u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1c7578: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7578u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c757c: 0xc4215070  lwc1        $f1, 0x5070($at)
    ctx->pc = 0x1c757cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20592)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c7580: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x1c7580u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x1c7584: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1c7584u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1c7588: 0x45010029  bc1t        . + 4 + (0x29 << 2)
    ctx->pc = 0x1C7588u;
    {
        const bool branch_taken_0x1c7588 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1c7588) {
            ctx->pc = 0x1C7630u;
            goto label_1c7630;
        }
    }
    ctx->pc = 0x1C7590u;
    // 0x1c7590: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7590u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7594: 0xc071f40  jal         func_1C7D00
    ctx->pc = 0x1C7594u;
    SET_GPR_U32(ctx, 31, 0x1C759Cu);
    ctx->pc = 0x1C7598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7594u;
            // 0x1c7598: 0x24844810  addiu       $a0, $a0, 0x4810 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D00u;
    if (runtime->hasFunction(0x1C7D00u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C759Cu; }
        if (ctx->pc != 0x1C759Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D00_0x1c7d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C759Cu; }
        if (ctx->pc != 0x1C759Cu) { return; }
    }
    ctx->pc = 0x1C759Cu;
label_1c759c:
    // 0x1c759c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c759cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c75a0: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c75a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c75a4: 0x90225054  lbu         $v0, 0x5054($at)
    ctx->pc = 0x1c75a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 20564)));
    // 0x1c75a8: 0x24844810  addiu       $a0, $a0, 0x4810
    ctx->pc = 0x1c75a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18448));
    // 0x1c75ac: 0x21300  sll         $v0, $v0, 12
    ctx->pc = 0x1c75acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 12));
    // 0x1c75b0: 0xc071f54  jal         func_1C7D50
    ctx->pc = 0x1C75B0u;
    SET_GPR_U32(ctx, 31, 0x1C75B8u);
    ctx->pc = 0x1C75B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C75B0u;
            // 0x1c75b4: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D50u;
    if (runtime->hasFunction(0x1C7D50u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C75B8u; }
        if (ctx->pc != 0x1C75B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D50_0x1c7d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C75B8u; }
        if (ctx->pc != 0x1C75B8u) { return; }
    }
    ctx->pc = 0x1C75B8u;
label_1c75b8:
    // 0x1c75b8: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c75b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c75bc: 0xc071f30  jal         func_1C7CC0
    ctx->pc = 0x1C75BCu;
    SET_GPR_U32(ctx, 31, 0x1C75C4u);
    ctx->pc = 0x1C75C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C75BCu;
            // 0x1c75c0: 0x24844810  addiu       $a0, $a0, 0x4810 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7CC0u;
    if (runtime->hasFunction(0x1C7CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C75C4u; }
        if (ctx->pc != 0x1C75C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7CC0_0x1c7cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C75C4u; }
        if (ctx->pc != 0x1C75C4u) { return; }
    }
    ctx->pc = 0x1C75C4u;
label_1c75c4:
    // 0x1c75c4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1c75c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c75c8: 0xc072f18  jal         func_1CBC60
    ctx->pc = 0x1C75C8u;
    SET_GPR_U32(ctx, 31, 0x1C75D0u);
    ctx->pc = 0x1C75CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C75C8u;
            // 0x1c75cc: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBC60u;
    if (runtime->hasFunction(0x1CBC60u)) {
        auto targetFn = runtime->lookupFunction(0x1CBC60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C75D0u; }
        if (ctx->pc != 0x1C75D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBC60_0x1cbc60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C75D0u; }
        if (ctx->pc != 0x1C75D0u) { return; }
    }
    ctx->pc = 0x1C75D0u;
label_1c75d0:
    // 0x1c75d0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c75d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c75d4: 0x4a10013  bgez        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1C75D4u;
    {
        const bool branch_taken_0x1c75d4 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1c75d4) {
            ctx->pc = 0x1C7624u;
            goto label_1c7624;
        }
    }
    ctx->pc = 0x1C75DCu;
    // 0x1c75dc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1c75dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c75e0: 0xc071eb0  jal         func_1C7AC0
    ctx->pc = 0x1C75E0u;
    SET_GPR_U32(ctx, 31, 0x1C75E8u);
    ctx->pc = 0x1C75E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C75E0u;
            // 0x1c75e4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7AC0u;
    if (runtime->hasFunction(0x1C7AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C7AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C75E8u; }
        if (ctx->pc != 0x1C75E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7AC0_0x1c7ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C75E8u; }
        if (ctx->pc != 0x1C75E8u) { return; }
    }
    ctx->pc = 0x1C75E8u;
label_1c75e8:
    // 0x1c75e8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c75e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c75ec: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c75ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c75f0: 0x942451b8  lhu         $a0, 0x51B8($at)
    ctx->pc = 0x1c75f0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
    // 0x1c75f4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c75f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c75f8: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c75f8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c75fc: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1c75fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1c7600: 0x8c235f58  lw          $v1, 0x5F58($at)
    ctx->pc = 0x1c7600u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24408)));
    // 0x1c7604: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1c7604u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c7608: 0x1460002e  bnez        $v1, . + 4 + (0x2E << 2)
    ctx->pc = 0x1C7608u;
    {
        const bool branch_taken_0x1c7608 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c7608) {
            ctx->pc = 0x1C76C4u;
            goto label_1c76c4;
        }
    }
    ctx->pc = 0x1C7610u;
    // 0x1c7610: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1c7610u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c7614: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7614u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7618: 0xac2351b0  sw          $v1, 0x51B0($at)
    ctx->pc = 0x1c7618u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20912), GPR_U32(ctx, 3));
    // 0x1c761c: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1C761Cu;
    {
        const bool branch_taken_0x1c761c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C761Cu;
            // 0x1c7620: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c761c) {
            ctx->pc = 0x1C76C8u;
            goto label_1c76c8;
        }
    }
    ctx->pc = 0x1C7624u;
label_1c7624:
    // 0x1c7624: 0x18a00002  blez        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C7624u;
    {
        const bool branch_taken_0x1c7624 = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x1c7624) {
            ctx->pc = 0x1C7630u;
            goto label_1c7630;
        }
    }
    ctx->pc = 0x1C762Cu;
    // 0x1c762c: 0x26310002  addiu       $s1, $s1, 0x2
    ctx->pc = 0x1c762cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
label_1c7630:
    // 0x1c7630: 0x2113021  addu        $a2, $s0, $s1
    ctx->pc = 0x1c7630u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
label_1c7634:
    // 0x1c7634: 0x18c00023  blez        $a2, . + 4 + (0x23 << 2)
    ctx->pc = 0x1C7634u;
    {
        const bool branch_taken_0x1c7634 = (GPR_S64(ctx, 6) <= 0);
        if (branch_taken_0x1c7634) {
            ctx->pc = 0x1C76C4u;
            goto label_1c76c4;
        }
    }
    ctx->pc = 0x1C763Cu;
    // 0x1c763c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c763cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7640: 0x30c4ffff  andi        $a0, $a2, 0xFFFF
    ctx->pc = 0x1c7640u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x1c7644: 0x8c255088  lw          $a1, 0x5088($at)
    ctx->pc = 0x1c7644u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20616)));
    // 0x1c7648: 0x44860000  mtc1        $a2, $f0
    ctx->pc = 0x1c7648u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1c764c: 0x0  nop
    ctx->pc = 0x1c764cu;
    // NOP
    // 0x1c7650: 0x468000a0  cvt.s.w     $f2, $f0
    ctx->pc = 0x1c7650u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1c7654: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7654u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7658: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1c7658u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1c765c: 0x9423508e  lhu         $v1, 0x508E($at)
    ctx->pc = 0x1c765cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20622)));
    // 0x1c7660: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7660u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7664: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1c7664u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1c7668: 0xc4215198  lwc1        $f1, 0x5198($at)
    ctx->pc = 0x1c7668u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20888)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c766c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c766cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7670: 0xc4235060  lwc1        $f3, 0x5060($at)
    ctx->pc = 0x1c7670u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20576)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1c7674: 0x46020842  mul.s       $f1, $f1, $f2
    ctx->pc = 0x1c7674u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x1c7678: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7678u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c767c: 0xc4205194  lwc1        $f0, 0x5194($at)
    ctx->pc = 0x1c767cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20884)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c7680: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7680u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7684: 0xac255088  sw          $a1, 0x5088($at)
    ctx->pc = 0x1c7684u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20616), GPR_U32(ctx, 5));
    // 0x1c7688: 0x46001836  c.le.s      $f3, $f0
    ctx->pc = 0x1c7688u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[3], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1c768c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c768cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7690: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1C7690u;
    {
        const bool branch_taken_0x1c7690 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1C7694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7690u;
            // 0x1c7694: 0xa423508e  sh          $v1, 0x508E($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 20622), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7690) {
            ctx->pc = 0x1C76A8u;
            goto label_1c76a8;
        }
    }
    ctx->pc = 0x1C7698u;
    // 0x1c7698: 0x46011800  add.s       $f0, $f3, $f1
    ctx->pc = 0x1c7698u;
    ctx->f[0] = FPU_ADD_S(ctx->f[3], ctx->f[1]);
    // 0x1c769c: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c769cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c76a0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C76A0u;
    {
        const bool branch_taken_0x1c76a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C76A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C76A0u;
            // 0x1c76a4: 0xe4205194  swc1        $f0, 0x5194($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20884), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c76a0) {
            ctx->pc = 0x1C76B4u;
            goto label_1c76b4;
        }
    }
    ctx->pc = 0x1C76A8u;
label_1c76a8:
    // 0x1c76a8: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x1c76a8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1c76ac: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c76acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c76b0: 0xe4205194  swc1        $f0, 0x5194($at)
    ctx->pc = 0x1c76b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20884), bits); }
label_1c76b4:
    // 0x1c76b4: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c76b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c76b8: 0xc420506c  lwc1        $f0, 0x506C($at)
    ctx->pc = 0x1c76b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20588)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c76bc: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c76bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c76c0: 0xe4205070  swc1        $f0, 0x5070($at)
    ctx->pc = 0x1c76c0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20592), bits); }
label_1c76c4:
    // 0x1c76c4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c76c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1c76c8:
    // 0x1c76c8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c76c8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c76cc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c76ccu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c76d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C76D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C76D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C76D0u;
            // 0x1c76d4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C753Cu: goto label_1c753c;
            case 0x1C7550u: goto label_1c7550;
            case 0x1C759Cu: goto label_1c759c;
            case 0x1C75B8u: goto label_1c75b8;
            case 0x1C75C4u: goto label_1c75c4;
            case 0x1C75D0u: goto label_1c75d0;
            case 0x1C75E8u: goto label_1c75e8;
            case 0x1C7624u: goto label_1c7624;
            case 0x1C7630u: goto label_1c7630;
            case 0x1C7634u: goto label_1c7634;
            case 0x1C76A8u: goto label_1c76a8;
            case 0x1C76B4u: goto label_1c76b4;
            case 0x1C76C4u: goto label_1c76c4;
            case 0x1C76C8u: goto label_1c76c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C76D8u;
    // 0x1c76d8: 0x0  nop
    ctx->pc = 0x1c76d8u;
    // NOP
    // 0x1c76dc: 0x0  nop
    ctx->pc = 0x1c76dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
