#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2340
// Address: 0x1b2340 - 0x1b2790
void sub_001B2340_0x1b2340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2340_0x1b2340");
#endif

    switch (ctx->pc) {
        case 0x1b2350u: goto label_1b2350;
        case 0x1b2364u: goto label_1b2364;
        case 0x1b238cu: goto label_1b238c;
        case 0x1b240cu: goto label_1b240c;
        case 0x1b2468u: goto label_1b2468;
        case 0x1b24a4u: goto label_1b24a4;
        case 0x1b255cu: goto label_1b255c;
        case 0x1b25a4u: goto label_1b25a4;
        case 0x1b25c4u: goto label_1b25c4;
        case 0x1b2604u: goto label_1b2604;
        case 0x1b2648u: goto label_1b2648;
        case 0x1b2690u: goto label_1b2690;
        case 0x1b271cu: goto label_1b271c;
        case 0x1b2754u: goto label_1b2754;
        case 0x1b275cu: goto label_1b275c;
        case 0x1b2778u: goto label_1b2778;
        default: break;
    }

    ctx->pc = 0x1b2340u;

    // 0x1b2340: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b2340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b2344: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b2344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b2348: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b2348u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b234c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b234cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b2350:
    // 0x1b2350: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1b2350u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1b2354: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b2354u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2358: 0x248468e0  addiu       $a0, $a0, 0x68E0
    ctx->pc = 0x1b2358u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26848));
    // 0x1b235c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B235Cu;
    SET_GPR_U32(ctx, 31, 0x1B2364u);
    ctx->pc = 0x1B2360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B235Cu;
            // 0x1b2360: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2364u; }
        if (ctx->pc != 0x1B2364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2364u; }
        if (ctx->pc != 0x1B2364u) { return; }
    }
    ctx->pc = 0x1B2364u;
label_1b2364:
    // 0x1b2364: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b2364u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b2368: 0x2a030100  slti        $v1, $s0, 0x100
    ctx->pc = 0x1b2368u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b236c: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1B236Cu;
    {
        const bool branch_taken_0x1b236c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b236c) {
            ctx->pc = 0x1B2350u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2350;
        }
    }
    ctx->pc = 0x1B2374u;
    // 0x1b2374: 0x3c030031  lui         $v1, 0x31
    ctx->pc = 0x1b2374u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49 << 16));
    // 0x1b2378: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b2378u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b237c: 0x246368c0  addiu       $v1, $v1, 0x68C0
    ctx->pc = 0x1b237cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 26816));
    // 0x1b2380: 0x640800ff  daddiu      $t0, $zero, 0xFF
    ctx->pc = 0x1b2380u;
    SET_GPR_S64(ctx, 8, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)255);
    // 0x1b2384: 0xac2366b0  sw          $v1, 0x66B0($at)
    ctx->pc = 0x1b2384u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26288), GPR_U32(ctx, 3));
    // 0x1b2388: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b2388u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b238c:
    // 0x1b238c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b238cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b2390: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1b2390u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1b2394: 0x8c2666b0  lw          $a2, 0x66B0($at)
    ctx->pc = 0x1b2394u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26288)));
    // 0x1b2398: 0x2504ffff  addiu       $a0, $t0, -0x1
    ctx->pc = 0x1b2398u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x1b239c: 0x28e30100  slti        $v1, $a3, 0x100
    ctx->pc = 0x1b239cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b23a0: 0x24c5fffe  addiu       $a1, $a2, -0x2
    ctx->pc = 0x1b23a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967294));
    // 0x1b23a4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b23a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b23a8: 0xac2566b0  sw          $a1, 0x66B0($at)
    ctx->pc = 0x1b23a8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26288), GPR_U32(ctx, 5));
    // 0x1b23ac: 0xa4c8fffe  sh          $t0, -0x2($a2)
    ctx->pc = 0x1b23acu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 4294967294), (uint16_t)GPR_U32(ctx, 8));
    // 0x1b23b0: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1B23B0u;
    {
        const bool branch_taken_0x1b23b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B23B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B23B0u;
            // 0x1b23b4: 0x3088ffff  andi        $t0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b23b0) {
            ctx->pc = 0x1B238Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b238c;
        }
    }
    ctx->pc = 0x1B23B8u;
    // 0x1b23b8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b23b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b23bc: 0x24030100  addiu       $v1, $zero, 0x100
    ctx->pc = 0x1b23bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1b23c0: 0xa42068c0  sh          $zero, 0x68C0($at)
    ctx->pc = 0x1b23c0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26816), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b23c4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b23c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b23c8: 0xa42368c8  sh          $v1, 0x68C8($at)
    ctx->pc = 0x1b23c8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26824), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b23cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b23ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b23d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b23d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b23d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B23D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B23D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B23D4u;
            // 0x1b23d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2350u: goto label_1b2350;
            case 0x1B2364u: goto label_1b2364;
            case 0x1B238Cu: goto label_1b238c;
            case 0x1B240Cu: goto label_1b240c;
            case 0x1B241Cu: goto label_1b241c;
            case 0x1B2468u: goto label_1b2468;
            case 0x1B2480u: goto label_1b2480;
            case 0x1B24A4u: goto label_1b24a4;
            case 0x1B24ACu: goto label_1b24ac;
            case 0x1B251Cu: goto label_1b251c;
            case 0x1B2538u: goto label_1b2538;
            case 0x1B255Cu: goto label_1b255c;
            case 0x1B2560u: goto label_1b2560;
            case 0x1B25A4u: goto label_1b25a4;
            case 0x1B25B4u: goto label_1b25b4;
            case 0x1B25C4u: goto label_1b25c4;
            case 0x1B25CCu: goto label_1b25cc;
            case 0x1B2604u: goto label_1b2604;
            case 0x1B2608u: goto label_1b2608;
            case 0x1B2648u: goto label_1b2648;
            case 0x1B2658u: goto label_1b2658;
            case 0x1B2670u: goto label_1b2670;
            case 0x1B2690u: goto label_1b2690;
            case 0x1B2698u: goto label_1b2698;
            case 0x1B26DCu: goto label_1b26dc;
            case 0x1B26F8u: goto label_1b26f8;
            case 0x1B271Cu: goto label_1b271c;
            case 0x1B2720u: goto label_1b2720;
            case 0x1B2754u: goto label_1b2754;
            case 0x1B275Cu: goto label_1b275c;
            case 0x1B2778u: goto label_1b2778;
            case 0x1B2780u: goto label_1b2780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B23DCu;
    // 0x1b23dc: 0x0  nop
    ctx->pc = 0x1b23dcu;
    // NOP
    // 0x1b23e0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1b23e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1b23e4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b23e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b23e8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b23e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b23ec: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b23ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b23f0: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1b23f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b23f4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b23f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b23f8: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1b23f8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b23fc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b23fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b2400: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1b2400u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2404: 0xc06c9e4  jal         func_1B2790
    ctx->pc = 0x1B2404u;
    SET_GPR_U32(ctx, 31, 0x1B240Cu);
    ctx->pc = 0x1B2408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2404u;
            // 0x1b2408: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2790u;
    if (runtime->hasFunction(0x1B2790u)) {
        auto targetFn = runtime->lookupFunction(0x1B2790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B240Cu; }
        if (ctx->pc != 0x1B240Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2790_0x1b2790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B240Cu; }
        if (ctx->pc != 0x1B240Cu) { return; }
    }
    ctx->pc = 0x1B240Cu;
label_1b240c:
    // 0x1b240c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B240Cu;
    {
        const bool branch_taken_0x1b240c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B240Cu;
            // 0x1b2410: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b240c) {
            ctx->pc = 0x1B241Cu;
            goto label_1b241c;
        }
    }
    ctx->pc = 0x1B2414u;
    // 0x1b2414: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x1B2414u;
    {
        const bool branch_taken_0x1b2414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2414u;
            // 0x1b2418: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2414) {
            ctx->pc = 0x1B2560u;
            goto label_1b2560;
        }
    }
    ctx->pc = 0x1B241Cu;
label_1b241c:
    // 0x1b241c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b241cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2420: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1b2420u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1b2424: 0xc4224138  lwc1        $f2, 0x4138($at)
    ctx->pc = 0x1b2424u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16696)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b2428: 0x27a50070  addiu       $a1, $sp, 0x70
    ctx->pc = 0x1b2428u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1b242c: 0x27b10068  addiu       $s1, $sp, 0x68
    ctx->pc = 0x1b242cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x1b2430: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2430u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2434: 0xc421413c  lwc1        $f1, 0x413C($at)
    ctx->pc = 0x1b2434u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16700)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b2438: 0xe7a20080  swc1        $f2, 0x80($sp)
    ctx->pc = 0x1b2438u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 128), bits); }
    // 0x1b243c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b243cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2440: 0xc4204140  lwc1        $f0, 0x4140($at)
    ctx->pc = 0x1b2440u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16704)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b2444: 0xe7a10084  swc1        $f1, 0x84($sp)
    ctx->pc = 0x1b2444u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 132), bits); }
    // 0x1b2448: 0xe7a00088  swc1        $f0, 0x88($sp)
    ctx->pc = 0x1b2448u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 136), bits); }
    // 0x1b244c: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1b244cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b2450: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x1b2450u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x1b2454: 0xc6400004  lwc1        $f0, 0x4($s2)
    ctx->pc = 0x1b2454u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b2458: 0xe7a00074  swc1        $f0, 0x74($sp)
    ctx->pc = 0x1b2458u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x1b245c: 0xc6400008  lwc1        $f0, 0x8($s2)
    ctx->pc = 0x1b245cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b2460: 0xc064744  jal         func_191D10
    ctx->pc = 0x1B2460u;
    SET_GPR_U32(ctx, 31, 0x1B2468u);
    ctx->pc = 0x1B2464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2460u;
            // 0x1b2464: 0xe7a00078  swc1        $f0, 0x78($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D10u;
    if (runtime->hasFunction(0x191D10u)) {
        auto targetFn = runtime->lookupFunction(0x191D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2468u; }
        if (ctx->pc != 0x1B2468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D10_0x191d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2468u; }
        if (ctx->pc != 0x1B2468u) { return; }
    }
    ctx->pc = 0x1B2468u;
label_1b2468:
    // 0x1b2468: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x1b2468u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b246c: 0x0  nop
    ctx->pc = 0x1b246cu;
    // NOP
    // 0x1b2470: 0x46010034  c.lt.s      $f0, $f1
    ctx->pc = 0x1b2470u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2474: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1B2474u;
    {
        const bool branch_taken_0x1b2474 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B2478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2474u;
            // 0x1b2478: 0xe6200000  swc1        $f0, 0x0($s1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2474) {
            ctx->pc = 0x1B2480u;
            goto label_1b2480;
        }
    }
    ctx->pc = 0x1B247Cu;
    // 0x1b247c: 0xe6210000  swc1        $f1, 0x0($s1)
    ctx->pc = 0x1b247cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
label_1b2480:
    // 0x1b2480: 0x3402c350  ori         $v0, $zero, 0xC350
    ctx->pc = 0x1b2480u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)50000);
    // 0x1b2484: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b2484u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b2488: 0xc6210000  lwc1        $f1, 0x0($s1)
    ctx->pc = 0x1b2488u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b248c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1b248cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1b2490: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1b2490u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2494: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B2494u;
    {
        const bool branch_taken_0x1b2494 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b2494) {
            ctx->pc = 0x1B24ACu;
            goto label_1b24ac;
        }
    }
    ctx->pc = 0x1B249Cu;
    // 0x1b249c: 0xc06ca04  jal         func_1B2810
    ctx->pc = 0x1B249Cu;
    SET_GPR_U32(ctx, 31, 0x1B24A4u);
    ctx->pc = 0x1B2810u;
    if (runtime->hasFunction(0x1B2810u)) {
        auto targetFn = runtime->lookupFunction(0x1B2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B24A4u; }
        if (ctx->pc != 0x1B24A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2810_0x1b2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B24A4u; }
        if (ctx->pc != 0x1B24A4u) { return; }
    }
    ctx->pc = 0x1B24A4u;
label_1b24a4:
    // 0x1b24a4: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1B24A4u;
    {
        const bool branch_taken_0x1b24a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B24A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B24A4u;
            // 0x1b24a8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b24a4) {
            ctx->pc = 0x1B2560u;
            goto label_1b2560;
        }
    }
    ctx->pc = 0x1B24ACu;
label_1b24ac:
    // 0x1b24ac: 0x0  nop
    ctx->pc = 0x1b24acu;
    // NOP
    // 0x1b24b0: 0x0  nop
    ctx->pc = 0x1b24b0u;
    // NOP
    // 0x1b24b4: 0x46000883  div.s       $f2, $f1, $f0
    ctx->pc = 0x1b24b4u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[1] / ctx->f[0];
    // 0x1b24b8: 0xae14001c  sw          $s4, 0x1C($s0)
    ctx->pc = 0x1b24b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 20));
    // 0x1b24bc: 0xae130018  sw          $s3, 0x18($s0)
    ctx->pc = 0x1b24bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 19));
    // 0x1b24c0: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1b24c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1b24c4: 0x3c034300  lui         $v1, 0x4300
    ctx->pc = 0x1b24c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17152 << 16));
    // 0x1b24c8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1b24c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1b24cc: 0xc4840000  lwc1        $f4, 0x0($a0)
    ctx->pc = 0x1b24ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1b24d0: 0xc4830004  lwc1        $f3, 0x4($a0)
    ctx->pc = 0x1b24d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1b24d4: 0xc4810008  lwc1        $f1, 0x8($a0)
    ctx->pc = 0x1b24d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b24d8: 0xc480000c  lwc1        $f0, 0xC($a0)
    ctx->pc = 0x1b24d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b24dc: 0xe6040008  swc1        $f4, 0x8($s0)
    ctx->pc = 0x1b24dcu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
    // 0x1b24e0: 0xe603000c  swc1        $f3, 0xC($s0)
    ctx->pc = 0x1b24e0u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 12), bits); }
    // 0x1b24e4: 0xe6010010  swc1        $f1, 0x10($s0)
    ctx->pc = 0x1b24e4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 16), bits); }
    // 0x1b24e8: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1b24e8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b24ec: 0x0  nop
    ctx->pc = 0x1b24ecu;
    // NOP
    // 0x1b24f0: 0xe6000014  swc1        $f0, 0x14($s0)
    ctx->pc = 0x1b24f0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 20), bits); }
    // 0x1b24f4: 0x46020842  mul.s       $f1, $f1, $f2
    ctx->pc = 0x1b24f4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x1b24f8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b24f8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b24fc: 0x0  nop
    ctx->pc = 0x1b24fcu;
    // NOP
    // 0x1b2500: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1b2500u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2504: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B2504u;
    {
        const bool branch_taken_0x1b2504 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b2504) {
            ctx->pc = 0x1B251Cu;
            goto label_1b251c;
        }
    }
    ctx->pc = 0x1B250Cu;
    // 0x1b250c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b250cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b2510: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1b2510u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b2514: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B2514u;
    {
        const bool branch_taken_0x1b2514 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2514u;
            // 0x1b2518: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2514) {
            ctx->pc = 0x1B2538u;
            goto label_1b2538;
        }
    }
    ctx->pc = 0x1B251Cu;
label_1b251c:
    // 0x1b251c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1b251cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1b2520: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1b2520u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1b2524: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b2524u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b2528: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1b2528u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b252c: 0x0  nop
    ctx->pc = 0x1b252cu;
    // NOP
    // 0x1b2530: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1b2530u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1b2534: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1b2534u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
label_1b2538:
    // 0x1b2538: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b2538u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b253c: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x1b253cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b2540: 0x2403007f  addiu       $v1, $zero, 0x7F
    ctx->pc = 0x1b2540u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1b2544: 0x244288e0  addiu       $v0, $v0, -0x7720
    ctx->pc = 0x1b2544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936800));
    // 0x1b2548: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b2548u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b254c: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x1b254cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1b2550: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b2550u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b2554: 0xc06ca14  jal         func_1B2850
    ctx->pc = 0x1B2554u;
    SET_GPR_U32(ctx, 31, 0x1B255Cu);
    ctx->pc = 0x1B2558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2554u;
            // 0x1b2558: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2850u;
    if (runtime->hasFunction(0x1B2850u)) {
        auto targetFn = runtime->lookupFunction(0x1B2850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B255Cu; }
        if (ctx->pc != 0x1B255Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2850_0x1b2850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B255Cu; }
        if (ctx->pc != 0x1B255Cu) { return; }
    }
    ctx->pc = 0x1B255Cu;
label_1b255c:
    // 0x1b255c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1b255cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_1b2560:
    // 0x1b2560: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b2560u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b2564: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b2564u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b2568: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b2568u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b256c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b256cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b2570: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b2570u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2574: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b2574u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2578: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2578u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B257Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2578u;
            // 0x1b257c: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2350u: goto label_1b2350;
            case 0x1B2364u: goto label_1b2364;
            case 0x1B238Cu: goto label_1b238c;
            case 0x1B240Cu: goto label_1b240c;
            case 0x1B241Cu: goto label_1b241c;
            case 0x1B2468u: goto label_1b2468;
            case 0x1B2480u: goto label_1b2480;
            case 0x1B24A4u: goto label_1b24a4;
            case 0x1B24ACu: goto label_1b24ac;
            case 0x1B251Cu: goto label_1b251c;
            case 0x1B2538u: goto label_1b2538;
            case 0x1B255Cu: goto label_1b255c;
            case 0x1B2560u: goto label_1b2560;
            case 0x1B25A4u: goto label_1b25a4;
            case 0x1B25B4u: goto label_1b25b4;
            case 0x1B25C4u: goto label_1b25c4;
            case 0x1B25CCu: goto label_1b25cc;
            case 0x1B2604u: goto label_1b2604;
            case 0x1B2608u: goto label_1b2608;
            case 0x1B2648u: goto label_1b2648;
            case 0x1B2658u: goto label_1b2658;
            case 0x1B2670u: goto label_1b2670;
            case 0x1B2690u: goto label_1b2690;
            case 0x1B2698u: goto label_1b2698;
            case 0x1B26DCu: goto label_1b26dc;
            case 0x1B26F8u: goto label_1b26f8;
            case 0x1B271Cu: goto label_1b271c;
            case 0x1B2720u: goto label_1b2720;
            case 0x1B2754u: goto label_1b2754;
            case 0x1B275Cu: goto label_1b275c;
            case 0x1B2778u: goto label_1b2778;
            case 0x1B2780u: goto label_1b2780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2580u;
    // 0x1b2580: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b2580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b2584: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b2584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b2588: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b2588u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b258c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b258cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b2590: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b2590u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2594: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b2594u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b2598: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1b2598u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b259c: 0xc06c9e4  jal         func_1B2790
    ctx->pc = 0x1B259Cu;
    SET_GPR_U32(ctx, 31, 0x1B25A4u);
    ctx->pc = 0x1B25A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B259Cu;
            // 0x1b25a0: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2790u;
    if (runtime->hasFunction(0x1B2790u)) {
        auto targetFn = runtime->lookupFunction(0x1B2790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B25A4u; }
        if (ctx->pc != 0x1B25A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2790_0x1b2790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B25A4u; }
        if (ctx->pc != 0x1B25A4u) { return; }
    }
    ctx->pc = 0x1B25A4u;
label_1b25a4:
    // 0x1b25a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B25A4u;
    {
        const bool branch_taken_0x1b25a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B25A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B25A4u;
            // 0x1b25a8: 0x2a030100  slti        $v1, $s0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b25a4) {
            ctx->pc = 0x1B25B4u;
            goto label_1b25b4;
        }
    }
    ctx->pc = 0x1B25ACu;
    // 0x1b25ac: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1B25ACu;
    {
        const bool branch_taken_0x1b25ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B25B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B25ACu;
            // 0x1b25b0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b25ac) {
            ctx->pc = 0x1B2608u;
            goto label_1b2608;
        }
    }
    ctx->pc = 0x1B25B4u;
label_1b25b4:
    // 0x1b25b4: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B25B4u;
    {
        const bool branch_taken_0x1b25b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b25b4) {
            ctx->pc = 0x1B25CCu;
            goto label_1b25cc;
        }
    }
    ctx->pc = 0x1B25BCu;
    // 0x1b25bc: 0xc06ca04  jal         func_1B2810
    ctx->pc = 0x1B25BCu;
    SET_GPR_U32(ctx, 31, 0x1B25C4u);
    ctx->pc = 0x1B2810u;
    if (runtime->hasFunction(0x1B2810u)) {
        auto targetFn = runtime->lookupFunction(0x1B2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B25C4u; }
        if (ctx->pc != 0x1B25C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2810_0x1b2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B25C4u; }
        if (ctx->pc != 0x1B25C4u) { return; }
    }
    ctx->pc = 0x1B25C4u;
label_1b25c4:
    // 0x1b25c4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1B25C4u;
    {
        const bool branch_taken_0x1b25c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B25C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B25C4u;
            // 0x1b25c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b25c4) {
            ctx->pc = 0x1B2608u;
            goto label_1b2608;
        }
    }
    ctx->pc = 0x1B25CCu;
label_1b25cc:
    // 0x1b25cc: 0xac52001c  sw          $s2, 0x1C($v0)
    ctx->pc = 0x1b25ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 18));
    // 0x1b25d0: 0x2403009f  addiu       $v1, $zero, 0x9F
    ctx->pc = 0x1b25d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 159));
    // 0x1b25d4: 0xac510018  sw          $s1, 0x18($v0)
    ctx->pc = 0x1b25d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 17));
    // 0x1b25d8: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1b25d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b25dc: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x1b25dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x1b25e0: 0x3c010025  lui         $at, 0x25
    ctx->pc = 0x1b25e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)37 << 16));
    // 0x1b25e4: 0xc420ff08  lwc1        $f0, -0xF8($at)
    ctx->pc = 0x1b25e4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294967048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b25e8: 0x32080  sll         $a0, $v1, 2
    ctx->pc = 0x1b25e8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b25ec: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b25ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b25f0: 0x246388e0  addiu       $v1, $v1, -0x7720
    ctx->pc = 0x1b25f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294936800));
    // 0x1b25f4: 0x642821  addu        $a1, $v1, $a0
    ctx->pc = 0x1b25f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b25f8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1b25f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b25fc: 0xc069704  jal         func_1A5C10
    ctx->pc = 0x1B25FCu;
    SET_GPR_U32(ctx, 31, 0x1B2604u);
    ctx->pc = 0x1B2600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B25FCu;
            // 0x1b2600: 0xe4400010  swc1        $f0, 0x10($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 16), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5C10u;
    if (runtime->hasFunction(0x1A5C10u)) {
        auto targetFn = runtime->lookupFunction(0x1A5C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2604u; }
        if (ctx->pc != 0x1B2604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5C10_0x1a5c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2604u; }
        if (ctx->pc != 0x1B2604u) { return; }
    }
    ctx->pc = 0x1B2604u;
label_1b2604:
    // 0x1b2604: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1b2604u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1b2608:
    // 0x1b2608: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b2608u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b260c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b260cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b2610: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b2610u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2614: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b2614u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2618: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B261Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2618u;
            // 0x1b261c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2350u: goto label_1b2350;
            case 0x1B2364u: goto label_1b2364;
            case 0x1B238Cu: goto label_1b238c;
            case 0x1B240Cu: goto label_1b240c;
            case 0x1B241Cu: goto label_1b241c;
            case 0x1B2468u: goto label_1b2468;
            case 0x1B2480u: goto label_1b2480;
            case 0x1B24A4u: goto label_1b24a4;
            case 0x1B24ACu: goto label_1b24ac;
            case 0x1B251Cu: goto label_1b251c;
            case 0x1B2538u: goto label_1b2538;
            case 0x1B255Cu: goto label_1b255c;
            case 0x1B2560u: goto label_1b2560;
            case 0x1B25A4u: goto label_1b25a4;
            case 0x1B25B4u: goto label_1b25b4;
            case 0x1B25C4u: goto label_1b25c4;
            case 0x1B25CCu: goto label_1b25cc;
            case 0x1B2604u: goto label_1b2604;
            case 0x1B2608u: goto label_1b2608;
            case 0x1B2648u: goto label_1b2648;
            case 0x1B2658u: goto label_1b2658;
            case 0x1B2670u: goto label_1b2670;
            case 0x1B2690u: goto label_1b2690;
            case 0x1B2698u: goto label_1b2698;
            case 0x1B26DCu: goto label_1b26dc;
            case 0x1B26F8u: goto label_1b26f8;
            case 0x1B271Cu: goto label_1b271c;
            case 0x1B2720u: goto label_1b2720;
            case 0x1B2754u: goto label_1b2754;
            case 0x1B275Cu: goto label_1b275c;
            case 0x1B2778u: goto label_1b2778;
            case 0x1B2780u: goto label_1b2780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2620u;
    // 0x1b2620: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b2620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b2624: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1b2624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1b2628: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x1b2628u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x1b262c: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1b262cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1b2630: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b2630u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2634: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1b2634u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1b2638: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1b2638u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b263c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1b263cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1b2640: 0xc06c9e4  jal         func_1B2790
    ctx->pc = 0x1B2640u;
    SET_GPR_U32(ctx, 31, 0x1B2648u);
    ctx->pc = 0x1B2644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2640u;
            // 0x1b2644: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2790u;
    if (runtime->hasFunction(0x1B2790u)) {
        auto targetFn = runtime->lookupFunction(0x1B2790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2648u; }
        if (ctx->pc != 0x1B2648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2790_0x1b2790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2648u; }
        if (ctx->pc != 0x1B2648u) { return; }
    }
    ctx->pc = 0x1B2648u;
label_1b2648:
    // 0x1b2648: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B2648u;
    {
        const bool branch_taken_0x1b2648 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B264Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2648u;
            // 0x1b264c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2648) {
            ctx->pc = 0x1B2658u;
            goto label_1b2658;
        }
    }
    ctx->pc = 0x1B2650u;
    // 0x1b2650: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1B2650u;
    {
        const bool branch_taken_0x1b2650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2650u;
            // 0x1b2654: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2650) {
            ctx->pc = 0x1B2720u;
            goto label_1b2720;
        }
    }
    ctx->pc = 0x1B2658u;
label_1b2658:
    // 0x1b2658: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1b2658u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b265c: 0x0  nop
    ctx->pc = 0x1b265cu;
    // NOP
    // 0x1b2660: 0x4600a034  c.lt.s      $f20, $f0
    ctx->pc = 0x1b2660u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2664: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1B2664u;
    {
        const bool branch_taken_0x1b2664 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B2668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2664u;
            // 0x1b2668: 0x3402c350  ori         $v0, $zero, 0xC350 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)50000);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2664) {
            ctx->pc = 0x1B2670u;
            goto label_1b2670;
        }
    }
    ctx->pc = 0x1B266Cu;
    // 0x1b266c: 0x46000506  mov.s       $f20, $f0
    ctx->pc = 0x1b266cu;
    ctx->f[20] = FPU_MOV_S(ctx->f[0]);
label_1b2670:
    // 0x1b2670: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b2670u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b2674: 0x0  nop
    ctx->pc = 0x1b2674u;
    // NOP
    // 0x1b2678: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1b2678u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1b267c: 0x4600a036  c.le.s      $f20, $f0
    ctx->pc = 0x1b267cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2680: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B2680u;
    {
        const bool branch_taken_0x1b2680 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b2680) {
            ctx->pc = 0x1B2698u;
            goto label_1b2698;
        }
    }
    ctx->pc = 0x1B2688u;
    // 0x1b2688: 0xc06ca04  jal         func_1B2810
    ctx->pc = 0x1B2688u;
    SET_GPR_U32(ctx, 31, 0x1B2690u);
    ctx->pc = 0x1B2810u;
    if (runtime->hasFunction(0x1B2810u)) {
        auto targetFn = runtime->lookupFunction(0x1B2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2690u; }
        if (ctx->pc != 0x1B2690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2810_0x1b2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2690u; }
        if (ctx->pc != 0x1B2690u) { return; }
    }
    ctx->pc = 0x1B2690u;
label_1b2690:
    // 0x1b2690: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1B2690u;
    {
        const bool branch_taken_0x1b2690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2690u;
            // 0x1b2694: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2690) {
            ctx->pc = 0x1B2720u;
            goto label_1b2720;
        }
    }
    ctx->pc = 0x1B2698u;
label_1b2698:
    // 0x1b2698: 0xae12001c  sw          $s2, 0x1C($s0)
    ctx->pc = 0x1b2698u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 18));
    // 0x1b269c: 0x0  nop
    ctx->pc = 0x1b269cu;
    // NOP
    // 0x1b26a0: 0x4600a083  div.s       $f2, $f20, $f0
    ctx->pc = 0x1b26a0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[20] / ctx->f[0];
    // 0x1b26a4: 0x3c034300  lui         $v1, 0x4300
    ctx->pc = 0x1b26a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17152 << 16));
    // 0x1b26a8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1b26a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1b26ac: 0xae110018  sw          $s1, 0x18($s0)
    ctx->pc = 0x1b26acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 17));
    // 0x1b26b0: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1b26b0u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b26b4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b26b4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b26b8: 0x0  nop
    ctx->pc = 0x1b26b8u;
    // NOP
    // 0x1b26bc: 0x46020842  mul.s       $f1, $f1, $f2
    ctx->pc = 0x1b26bcu;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x1b26c0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1b26c0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b26c4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B26C4u;
    {
        const bool branch_taken_0x1b26c4 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B26C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B26C4u;
            // 0x1b26c8: 0xe6140010  swc1        $f20, 0x10($s0) (Delay Slot)
        { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 16), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b26c4) {
            ctx->pc = 0x1B26DCu;
            goto label_1b26dc;
        }
    }
    ctx->pc = 0x1B26CCu;
    // 0x1b26cc: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b26ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b26d0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1b26d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b26d4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B26D4u;
    {
        const bool branch_taken_0x1b26d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B26D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B26D4u;
            // 0x1b26d8: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b26d4) {
            ctx->pc = 0x1B26F8u;
            goto label_1b26f8;
        }
    }
    ctx->pc = 0x1B26DCu;
label_1b26dc:
    // 0x1b26dc: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1b26dcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1b26e0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1b26e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1b26e4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b26e4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b26e8: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1b26e8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b26ec: 0x0  nop
    ctx->pc = 0x1b26ecu;
    // NOP
    // 0x1b26f0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1b26f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1b26f4: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1b26f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
label_1b26f8:
    // 0x1b26f8: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b26f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b26fc: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x1b26fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b2700: 0x2403007f  addiu       $v1, $zero, 0x7F
    ctx->pc = 0x1b2700u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1b2704: 0x244288e0  addiu       $v0, $v0, -0x7720
    ctx->pc = 0x1b2704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936800));
    // 0x1b2708: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b2708u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b270c: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x1b270cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1b2710: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b2710u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b2714: 0xc06ca14  jal         func_1B2850
    ctx->pc = 0x1B2714u;
    SET_GPR_U32(ctx, 31, 0x1B271Cu);
    ctx->pc = 0x1B2718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2714u;
            // 0x1b2718: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2850u;
    if (runtime->hasFunction(0x1B2850u)) {
        auto targetFn = runtime->lookupFunction(0x1B2850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B271Cu; }
        if (ctx->pc != 0x1B271Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2850_0x1b2850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B271Cu; }
        if (ctx->pc != 0x1B271Cu) { return; }
    }
    ctx->pc = 0x1B271Cu;
label_1b271c:
    // 0x1b271c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1b271cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_1b2720:
    // 0x1b2720: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1b2720u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b2724: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1b2724u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1b2728: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1b2728u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b272c: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1b272cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b2730: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1b2730u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2734: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2734u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2734u;
            // 0x1b2738: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2350u: goto label_1b2350;
            case 0x1B2364u: goto label_1b2364;
            case 0x1B238Cu: goto label_1b238c;
            case 0x1B240Cu: goto label_1b240c;
            case 0x1B241Cu: goto label_1b241c;
            case 0x1B2468u: goto label_1b2468;
            case 0x1B2480u: goto label_1b2480;
            case 0x1B24A4u: goto label_1b24a4;
            case 0x1B24ACu: goto label_1b24ac;
            case 0x1B251Cu: goto label_1b251c;
            case 0x1B2538u: goto label_1b2538;
            case 0x1B255Cu: goto label_1b255c;
            case 0x1B2560u: goto label_1b2560;
            case 0x1B25A4u: goto label_1b25a4;
            case 0x1B25B4u: goto label_1b25b4;
            case 0x1B25C4u: goto label_1b25c4;
            case 0x1B25CCu: goto label_1b25cc;
            case 0x1B2604u: goto label_1b2604;
            case 0x1B2608u: goto label_1b2608;
            case 0x1B2648u: goto label_1b2648;
            case 0x1B2658u: goto label_1b2658;
            case 0x1B2670u: goto label_1b2670;
            case 0x1B2690u: goto label_1b2690;
            case 0x1B2698u: goto label_1b2698;
            case 0x1B26DCu: goto label_1b26dc;
            case 0x1B26F8u: goto label_1b26f8;
            case 0x1B271Cu: goto label_1b271c;
            case 0x1B2720u: goto label_1b2720;
            case 0x1B2754u: goto label_1b2754;
            case 0x1B275Cu: goto label_1b275c;
            case 0x1B2778u: goto label_1b2778;
            case 0x1B2780u: goto label_1b2780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B273Cu;
    // 0x1b273c: 0x0  nop
    ctx->pc = 0x1b273cu;
    // NOP
    // 0x1b2740: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b2740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b2744: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b2744u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b2748: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b2748u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b274c: 0x244288e0  addiu       $v0, $v0, -0x7720
    ctx->pc = 0x1b274cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936800));
    // 0x1b2750: 0xafa2001c  sw          $v0, 0x1C($sp)
    ctx->pc = 0x1b2750u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
label_1b2754:
    // 0x1b2754: 0xc06970c  jal         func_1A5C30
    ctx->pc = 0x1B2754u;
    SET_GPR_U32(ctx, 31, 0x1B275Cu);
    ctx->pc = 0x1B2758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2754u;
            // 0x1b2758: 0x27a4001c  addiu       $a0, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5C30u;
    if (runtime->hasFunction(0x1A5C30u)) {
        auto targetFn = runtime->lookupFunction(0x1A5C30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B275Cu; }
        if (ctx->pc != 0x1B275Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5C30_0x1a5c30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B275Cu; }
        if (ctx->pc != 0x1B275Cu) { return; }
    }
    ctx->pc = 0x1B275Cu;
label_1b275c:
    // 0x1b275c: 0xafa2001c  sw          $v0, 0x1C($sp)
    ctx->pc = 0x1b275cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x1b2760: 0x8fa4001c  lw          $a0, 0x1C($sp)
    ctx->pc = 0x1b2760u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1b2764: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B2764u;
    {
        const bool branch_taken_0x1b2764 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2764) {
            ctx->pc = 0x1B2780u;
            goto label_1b2780;
        }
    }
    ctx->pc = 0x1B276Cu;
    // 0x1b276c: 0x8c82001c  lw          $v0, 0x1C($a0)
    ctx->pc = 0x1b276cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1b2770: 0x40f809  jalr        $v0
    ctx->pc = 0x1B2770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B2778u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1B2778u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2350u: goto label_1b2350;
            case 0x1B2364u: goto label_1b2364;
            case 0x1B238Cu: goto label_1b238c;
            case 0x1B240Cu: goto label_1b240c;
            case 0x1B241Cu: goto label_1b241c;
            case 0x1B2468u: goto label_1b2468;
            case 0x1B2480u: goto label_1b2480;
            case 0x1B24A4u: goto label_1b24a4;
            case 0x1B24ACu: goto label_1b24ac;
            case 0x1B251Cu: goto label_1b251c;
            case 0x1B2538u: goto label_1b2538;
            case 0x1B255Cu: goto label_1b255c;
            case 0x1B2560u: goto label_1b2560;
            case 0x1B25A4u: goto label_1b25a4;
            case 0x1B25B4u: goto label_1b25b4;
            case 0x1B25C4u: goto label_1b25c4;
            case 0x1B25CCu: goto label_1b25cc;
            case 0x1B2604u: goto label_1b2604;
            case 0x1B2608u: goto label_1b2608;
            case 0x1B2648u: goto label_1b2648;
            case 0x1B2658u: goto label_1b2658;
            case 0x1B2670u: goto label_1b2670;
            case 0x1B2690u: goto label_1b2690;
            case 0x1B2698u: goto label_1b2698;
            case 0x1B26DCu: goto label_1b26dc;
            case 0x1B26F8u: goto label_1b26f8;
            case 0x1B271Cu: goto label_1b271c;
            case 0x1B2720u: goto label_1b2720;
            case 0x1B2754u: goto label_1b2754;
            case 0x1B275Cu: goto label_1b275c;
            case 0x1B2778u: goto label_1b2778;
            case 0x1B2780u: goto label_1b2780;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B2778u; }
            if (ctx->pc != 0x1B2778u) { return; }
        }
        }
    }
    ctx->pc = 0x1B2778u;
label_1b2778:
    // 0x1b2778: 0x1000fff6  b           . + 4 + (-0xA << 2)
    ctx->pc = 0x1B2778u;
    {
        const bool branch_taken_0x1b2778 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2778) {
            ctx->pc = 0x1B2754u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b2754;
        }
    }
    ctx->pc = 0x1B2780u;
label_1b2780:
    // 0x1b2780: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b2780u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2784: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2784u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2784u;
            // 0x1b2788: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2350u: goto label_1b2350;
            case 0x1B2364u: goto label_1b2364;
            case 0x1B238Cu: goto label_1b238c;
            case 0x1B240Cu: goto label_1b240c;
            case 0x1B241Cu: goto label_1b241c;
            case 0x1B2468u: goto label_1b2468;
            case 0x1B2480u: goto label_1b2480;
            case 0x1B24A4u: goto label_1b24a4;
            case 0x1B24ACu: goto label_1b24ac;
            case 0x1B251Cu: goto label_1b251c;
            case 0x1B2538u: goto label_1b2538;
            case 0x1B255Cu: goto label_1b255c;
            case 0x1B2560u: goto label_1b2560;
            case 0x1B25A4u: goto label_1b25a4;
            case 0x1B25B4u: goto label_1b25b4;
            case 0x1B25C4u: goto label_1b25c4;
            case 0x1B25CCu: goto label_1b25cc;
            case 0x1B2604u: goto label_1b2604;
            case 0x1B2608u: goto label_1b2608;
            case 0x1B2648u: goto label_1b2648;
            case 0x1B2658u: goto label_1b2658;
            case 0x1B2670u: goto label_1b2670;
            case 0x1B2690u: goto label_1b2690;
            case 0x1B2698u: goto label_1b2698;
            case 0x1B26DCu: goto label_1b26dc;
            case 0x1B26F8u: goto label_1b26f8;
            case 0x1B271Cu: goto label_1b271c;
            case 0x1B2720u: goto label_1b2720;
            case 0x1B2754u: goto label_1b2754;
            case 0x1B275Cu: goto label_1b275c;
            case 0x1B2778u: goto label_1b2778;
            case 0x1B2780u: goto label_1b2780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B278Cu;
    // 0x1b278c: 0x0  nop
    ctx->pc = 0x1b278cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
