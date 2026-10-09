#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2600
// Address: 0x1a2600 - 0x1a26c0
void sub_001A2600_0x1a2600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2600_0x1a2600");
#endif

    switch (ctx->pc) {
        case 0x1a2644u: goto label_1a2644;
        case 0x1a2654u: goto label_1a2654;
        default: break;
    }

    ctx->pc = 0x1a2600u;

    // 0x1a2600: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a2600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a2604: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x1a2604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1a2608: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a2608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a260c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a260cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2610: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a2610u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a2614: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a2614u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a2618: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a2618u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a261c: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x1a261cu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a2620: 0x2490000c  addiu       $s0, $a0, 0xC
    ctx->pc = 0x1a2620u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1a2624: 0xa0a00001  sb          $zero, 0x1($a1)
    ctx->pc = 0x1a2624u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a2628: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x1a2628u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a262c: 0xa4a20002  sh          $v0, 0x2($a1)
    ctx->pc = 0x1a262cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a2630: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a2630u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a2634: 0x94a20002  lhu         $v0, 0x2($a1)
    ctx->pc = 0x1a2634u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1a2638: 0x2484ffc0  addiu       $a0, $a0, -0x40
    ctx->pc = 0x1a2638u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967232));
    // 0x1a263c: 0xc06267c  jal         func_1899F0
    ctx->pc = 0x1A263Cu;
    SET_GPR_U32(ctx, 31, 0x1A2644u);
    ctx->pc = 0x1A2640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A263Cu;
            // 0x1a2640: 0x22900  sll         $a1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1899F0u;
    if (runtime->hasFunction(0x1899F0u)) {
        auto targetFn = runtime->lookupFunction(0x1899F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2644u; }
        if (ctx->pc != 0x1A2644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001899F0_0x1899f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2644u; }
        if (ctx->pc != 0x1A2644u) { return; }
    }
    ctx->pc = 0x1A2644u;
label_1a2644:
    // 0x1a2644: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1a2644u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2648: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1a2648u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a264c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A264Cu;
    {
        const bool branch_taken_0x1a264c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A264Cu;
            // 0x1a2650: 0xae250004  sw          $a1, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a264c) {
            ctx->pc = 0x1A2680u;
            goto label_1a2680;
        }
    }
    ctx->pc = 0x1A2654u;
label_1a2654:
    // 0x1a2654: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x1a2654u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a2658: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1a2658u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1a265c: 0xe4a00000  swc1        $f0, 0x0($a1)
    ctx->pc = 0x1a265cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x1a2660: 0xc6000004  lwc1        $f0, 0x4($s0)
    ctx->pc = 0x1a2660u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a2664: 0xe4a00004  swc1        $f0, 0x4($a1)
    ctx->pc = 0x1a2664u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
    // 0x1a2668: 0xc6000008  lwc1        $f0, 0x8($s0)
    ctx->pc = 0x1a2668u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a266c: 0xe4a00008  swc1        $f0, 0x8($a1)
    ctx->pc = 0x1a266cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
    // 0x1a2670: 0xc600000c  lwc1        $f0, 0xC($s0)
    ctx->pc = 0x1a2670u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a2674: 0xe4a0000c  swc1        $f0, 0xC($a1)
    ctx->pc = 0x1a2674u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 12), bits); }
    // 0x1a2678: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x1a2678u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x1a267c: 0x24a50010  addiu       $a1, $a1, 0x10
    ctx->pc = 0x1a267cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
label_1a2680:
    // 0x1a2680: 0x96230002  lhu         $v1, 0x2($s1)
    ctx->pc = 0x1a2680u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1a2684: 0x83182a  slt         $v1, $a0, $v1
    ctx->pc = 0x1a2684u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a2688: 0x1460fff2  bnez        $v1, . + 4 + (-0xE << 2)
    ctx->pc = 0x1A2688u;
    {
        const bool branch_taken_0x1a2688 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A268Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2688u;
            // 0x1a268c: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2688) {
            ctx->pc = 0x1A2654u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2654;
        }
    }
    ctx->pc = 0x1A2690u;
    // 0x1a2690: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1a2690u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1a2694: 0x8c23ffb0  lw          $v1, -0x50($at)
    ctx->pc = 0x1a2694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967216)));
    // 0x1a2698: 0x831823  subu        $v1, $a0, $v1
    ctx->pc = 0x1a2698u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a269c: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1a269cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x1a26a0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a26a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a26a4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a26a4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a26a8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a26a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a26ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1A26ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A26B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A26ACu;
            // 0x1a26b0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2644u: goto label_1a2644;
            case 0x1A2654u: goto label_1a2654;
            case 0x1A2680u: goto label_1a2680;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A26B4u;
    // 0x1a26b4: 0x0  nop
    ctx->pc = 0x1a26b4u;
    // NOP
    // 0x1a26b8: 0x0  nop
    ctx->pc = 0x1a26b8u;
    // NOP
    // 0x1a26bc: 0x0  nop
    ctx->pc = 0x1a26bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
