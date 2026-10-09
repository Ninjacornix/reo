#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019C4C0
// Address: 0x19c4c0 - 0x19c754
void sub_0019C4C0_0x19c4c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019C4C0_0x19c4c0");
#endif

    switch (ctx->pc) {
        case 0x19c4ecu: goto label_19c4ec;
        case 0x19c5bcu: goto label_19c5bc;
        case 0x19c5ecu: goto label_19c5ec;
        case 0x19c610u: goto label_19c610;
        case 0x19c65cu: goto label_19c65c;
        case 0x19c674u: goto label_19c674;
        case 0x19c714u: goto label_19c714;
        case 0x19c724u: goto label_19c724;
        default: break;
    }

    ctx->pc = 0x19c4c0u;

    // 0x19c4c0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x19c4c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19c4c4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19c4c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19c4c8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19c4c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19c4cc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19c4ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c4d0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19c4d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c4d4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19c4d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19c4d8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19c4d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c4dc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19c4dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c4e0: 0x24040fa0  addiu       $a0, $zero, 0xFA0
    ctx->pc = 0x19c4e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4000));
    // 0x19c4e4: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19C4E4u;
    SET_GPR_U32(ctx, 31, 0x19C4ECu);
    ctx->pc = 0x19C4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C4E4u;
            // 0x19c4e8: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C4ECu; }
        if (ctx->pc != 0x19C4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C4ECu; }
        if (ctx->pc != 0x19C4ECu) { return; }
    }
    ctx->pc = 0x19C4ECu;
label_19c4ec:
    // 0x19c4ec: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19c4ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19c4f0: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19c4f0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19c4f4: 0x346400f9  ori         $a0, $v1, 0xF9
    ctx->pc = 0x19c4f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)249);
    // 0x19c4f8: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19c4f8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19c4fc: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19c4fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19c500: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19c500u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19c504: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19c504u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19c508: 0x34650404  ori         $a1, $v1, 0x404
    ctx->pc = 0x19c508u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19c50c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19c50cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19c510: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19c510u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19c514: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19c514u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19c518: 0x3c046cf7  lui         $a0, 0x6CF7
    ctx->pc = 0x19c518u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)27895 << 16));
    // 0x19c51c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19c51cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19c520: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19c520u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19c524: 0xac450018  sw          $a1, 0x18($v0)
    ctx->pc = 0x19c524u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19c528: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c528u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c52c: 0xac44001c  sw          $a0, 0x1C($v0)
    ctx->pc = 0x19c52cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19c530: 0x24e74d40  addiu       $a3, $a3, 0x4D40
    ctx->pc = 0x19c530u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19c534: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c534u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c538: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19c538u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c53c: 0x24460040  addiu       $a2, $v0, 0x40
    ctx->pc = 0x19c53cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19c540: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19c540u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x19c544: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19c544u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c548: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c548u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c54c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19c54cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19c550: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19c550u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19c554: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c554u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c558: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19c558u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c55c: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19c55cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c560: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c564: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19c564u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19c568: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19c568u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19c56c: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c56cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c570: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19c570u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c574: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19c574u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c578: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c578u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c57c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19c57cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19c580: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19c580u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19c584: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19c584u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c588: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19c588u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19c58c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19c58cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19c590: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19c590u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c594: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19c594u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19c598: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19c598u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19c59c: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19c59cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c5a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19c5a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19c5a4: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19c5a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c5a8: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19c5a8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19c5ac: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19c5acu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19c5b0: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19c5b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19c5b4: 0xac400038  sw          $zero, 0x38($v0)
    ctx->pc = 0x19c5b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19c5b8: 0xac40003c  sw          $zero, 0x3C($v0)
    ctx->pc = 0x19c5b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
label_19c5bc:
    // 0x19c5bc: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19c5bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19c5c0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19c5c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19c5c4: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19c5c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19c5c8: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19c5c8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19c5cc: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19c5ccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19c5d0: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19c5d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19c5d4: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19C5D4u;
    {
        const bool branch_taken_0x19c5d4 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19C5D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C5D4u;
            // 0x19c5d8: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c5d4) {
            ctx->pc = 0x19C5BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19c5bc;
        }
    }
    ctx->pc = 0x19C5DCu;
    // 0x19c5dc: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19c5dcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19c5e0: 0x24460080  addiu       $a2, $v0, 0x80
    ctx->pc = 0x19c5e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19c5e4: 0x24e74d00  addiu       $a3, $a3, 0x4D00
    ctx->pc = 0x19c5e4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19c5e8: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19c5e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19c5ec:
    // 0x19c5ec: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19c5ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19c5f0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19c5f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19c5f4: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19c5f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19c5f8: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19c5f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19c5fc: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19c5fcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19c600: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19c600u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19c604: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19C604u;
    {
        const bool branch_taken_0x19c604 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19C608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C604u;
            // 0x19c608: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c604) {
            ctx->pc = 0x19C5ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19c5ec;
        }
    }
    ctx->pc = 0x19C60Cu;
    // 0x19c60c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x19c60cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19c610:
    // 0x19c610: 0x8e430054  lw          $v1, 0x54($s2)
    ctx->pc = 0x19c610u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19c614: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x19c614u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19c618: 0x1042004  sllv        $a0, $a0, $t0
    ctx->pc = 0x19c618u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19c61c: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x19c61cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x19c620: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x19C620u;
    {
        const bool branch_taken_0x19c620 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x19C624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C620u;
            // 0x19c624: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c620) {
            ctx->pc = 0x19C65Cu;
            goto label_19c65c;
        }
    }
    ctx->pc = 0x19C628u;
    // 0x19c628: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19c628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19c62c: 0x682021  addu        $a0, $v1, $t0
    ctx->pc = 0x19c62cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19c630: 0x83180  sll         $a2, $t0, 6
    ctx->pc = 0x19c630u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 8), 6));
    // 0x19c634: 0x461821  addu        $v1, $v0, $a2
    ctx->pc = 0x19c634u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19c638: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x19c638u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x19c63c: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x19c63cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x19c640: 0x24650190  addiu       $a1, $v1, 0x190
    ctx->pc = 0x19c640u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 400));
    // 0x19c644: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x19c644u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19c648: 0xc13021  addu        $a2, $a2, $at
    ctx->pc = 0x19c648u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19c64c: 0x24640990  addiu       $a0, $v1, 0x990
    ctx->pc = 0x19c64cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2448));
    // 0x19c650: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19c650u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19c654: 0xc066538  jal         func_1994E0
    ctx->pc = 0x19C654u;
    SET_GPR_U32(ctx, 31, 0x19C65Cu);
    ctx->pc = 0x19C658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C654u;
            // 0x19c658: 0x34673f40  ori         $a3, $v1, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1994E0u;
    if (runtime->hasFunction(0x1994E0u)) {
        auto targetFn = runtime->lookupFunction(0x1994E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C65Cu; }
        if (ctx->pc != 0x19C65Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C65Cu; }
        if (ctx->pc != 0x19C65Cu) { return; }
    }
    ctx->pc = 0x19C65Cu;
label_19c65c:
    // 0x19c65c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x19c65cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x19c660: 0x29030020  slti        $v1, $t0, 0x20
    ctx->pc = 0x19c660u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x19c664: 0x1460ffea  bnez        $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x19C664u;
    {
        const bool branch_taken_0x19c664 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19C668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C664u;
            // 0x19c668: 0x244400c0  addiu       $a0, $v0, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c664) {
            ctx->pc = 0x19C610u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19c610;
        }
    }
    ctx->pc = 0x19C66Cu;
    // 0x19c66c: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19C66Cu;
    SET_GPR_U32(ctx, 31, 0x19C674u);
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C674u; }
        if (ctx->pc != 0x19C674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C674u; }
        if (ctx->pc != 0x19C674u) { return; }
    }
    ctx->pc = 0x19C674u;
label_19c674:
    // 0x19c674: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c674u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c678: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19c678u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19c67c: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19c67cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c680: 0xafa3004c  sw          $v1, 0x4C($sp)
    ctx->pc = 0x19c680u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19c684: 0xafa3005c  sw          $v1, 0x5C($sp)
    ctx->pc = 0x19c684u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19c688: 0x244400f0  addiu       $a0, $v0, 0xF0
    ctx->pc = 0x19c688u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 240));
    // 0x19c68c: 0xafa3006c  sw          $v1, 0x6C($sp)
    ctx->pc = 0x19c68cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19c690: 0x24450120  addiu       $a1, $v0, 0x120
    ctx->pc = 0x19c690u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 288));
    // 0x19c694: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19c694u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19c698: 0x27a70040  addiu       $a3, $sp, 0x40
    ctx->pc = 0x19c698u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19c69c: 0x34663f40  ori         $a2, $v1, 0x3F40
    ctx->pc = 0x19c69cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19c6a0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c6a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c6a4: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19c6a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c6a8: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19c6a8u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19c6ac: 0xe7a10040  swc1        $f1, 0x40($sp)
    ctx->pc = 0x19c6acu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19c6b0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c6b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c6b4: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19c6b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19c6b8: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19c6b8u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19c6bc: 0xe7a50044  swc1        $f5, 0x44($sp)
    ctx->pc = 0x19c6bcu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19c6c0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c6c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c6c4: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19c6c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19c6c8: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19c6c8u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19c6cc: 0xe7a40048  swc1        $f4, 0x48($sp)
    ctx->pc = 0x19c6ccu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19c6d0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c6d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c6d4: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19c6d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c6d8: 0xe7a30050  swc1        $f3, 0x50($sp)
    ctx->pc = 0x19c6d8u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19c6dc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c6dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c6e0: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19c6e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c6e4: 0xe7a20054  swc1        $f2, 0x54($sp)
    ctx->pc = 0x19c6e4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19c6e8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c6e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c6ec: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19c6ecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c6f0: 0xe7a10058  swc1        $f1, 0x58($sp)
    ctx->pc = 0x19c6f0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19c6f4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c6f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c6f8: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19c6f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c6fc: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x19c6fcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19c700: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c700u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c704: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19c704u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c708: 0xe7a10064  swc1        $f1, 0x64($sp)
    ctx->pc = 0x19c708u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19c70c: 0xc06661c  jal         func_199870
    ctx->pc = 0x19C70Cu;
    SET_GPR_U32(ctx, 31, 0x19C714u);
    ctx->pc = 0x19C710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C70Cu;
            // 0x19c710: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199870u;
    if (runtime->hasFunction(0x199870u)) {
        auto targetFn = runtime->lookupFunction(0x199870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C714u; }
        if (ctx->pc != 0x19C714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C714u; }
        if (ctx->pc != 0x19C714u) { return; }
    }
    ctx->pc = 0x19C714u;
label_19c714:
    // 0x19c714: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c714u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c718: 0xc46c0024  lwc1        $f12, 0x24($v1)
    ctx->pc = 0x19c718u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19c71c: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19C71Cu;
    SET_GPR_U32(ctx, 31, 0x19C724u);
    ctx->pc = 0x19C720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C71Cu;
            // 0x19c720: 0x24440130  addiu       $a0, $v0, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 304));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C724u; }
        if (ctx->pc != 0x19C724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C724u; }
        if (ctx->pc != 0x19C724u) { return; }
    }
    ctx->pc = 0x19C724u;
label_19c724:
    // 0x19c724: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19c724u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19c728: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19c728u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19c72c: 0xac430f90  sw          $v1, 0xF90($v0)
    ctx->pc = 0x19c72cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3984), GPR_U32(ctx, 3));
    // 0x19c730: 0xac400f94  sw          $zero, 0xF94($v0)
    ctx->pc = 0x19c730u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3988), GPR_U32(ctx, 0));
    // 0x19c734: 0xac400f98  sw          $zero, 0xF98($v0)
    ctx->pc = 0x19c734u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3992), GPR_U32(ctx, 0));
    // 0x19c738: 0xac400f9c  sw          $zero, 0xF9C($v0)
    ctx->pc = 0x19c738u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3996), GPR_U32(ctx, 0));
    // 0x19c73c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19c73cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c740: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19c740u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c744: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19c744u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c748: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19c748u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c74c: 0x3e00008  jr          $ra
    ctx->pc = 0x19C74Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C74Cu;
            // 0x19c750: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19C4ECu: goto label_19c4ec;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C674u: goto label_19c674;
            case 0x19C714u: goto label_19c714;
            case 0x19C724u: goto label_19c724;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C754u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
