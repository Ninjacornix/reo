#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001477A0
// Address: 0x1477a0 - 0x147a28
void sub_001477A0_0x1477a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001477A0_0x1477a0");
#endif

    switch (ctx->pc) {
        case 0x1477e8u: goto label_1477e8;
        case 0x147818u: goto label_147818;
        case 0x147840u: goto label_147840;
        case 0x147850u: goto label_147850;
        case 0x1478acu: goto label_1478ac;
        case 0x1478c8u: goto label_1478c8;
        case 0x1478d0u: goto label_1478d0;
        case 0x14790cu: goto label_14790c;
        case 0x147944u: goto label_147944;
        case 0x14795cu: goto label_14795c;
        case 0x147964u: goto label_147964;
        case 0x147970u: goto label_147970;
        case 0x147980u: goto label_147980;
        case 0x1479c0u: goto label_1479c0;
        case 0x1479d8u: goto label_1479d8;
        case 0x1479f0u: goto label_1479f0;
        case 0x147a04u: goto label_147a04;
        default: break;
    }

    ctx->pc = 0x1477a0u;

    // 0x1477a0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1477a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1477a4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1477a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1477a8: 0xffb30060  sd          $s3, 0x60($sp)
    ctx->pc = 0x1477a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 19));
    // 0x1477ac: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x1477acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x1477b0: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x1477b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x1477b4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1477b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1477b8: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1477b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1477bc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1477bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1477c0: 0xffb50080  sd          $s5, 0x80($sp)
    ctx->pc = 0x1477c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 21));
    // 0x1477c4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1477c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1477c8: 0xffb40070  sd          $s4, 0x70($sp)
    ctx->pc = 0x1477c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 20));
    // 0x1477cc: 0xffb10040  sd          $s1, 0x40($sp)
    ctx->pc = 0x1477ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 17));
    // 0x1477d0: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x1477d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1477d4: 0x8e420010  lw          $v0, 0x10($s2)
    ctx->pc = 0x1477d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1477d8: 0x8e040870  lw          $a0, 0x870($s0)
    ctx->pc = 0x1477d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x1477dc: 0x629818  mult        $s3, $v1, $v0
    ctx->pc = 0x1477dcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 19, (int32_t)result); }
    // 0x1477e0: 0xc051fda  jal         func_147F68
    ctx->pc = 0x1477E0u;
    SET_GPR_U32(ctx, 31, 0x1477E8u);
    ctx->pc = 0x1477E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1477E0u;
            // 0x1477e4: 0xafa60000  sw          $a2, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F68u;
    if (runtime->hasFunction(0x147F68u)) {
        auto targetFn = runtime->lookupFunction(0x147F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1477E8u; }
        if (ctx->pc != 0x1477E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1477E8u; }
        if (ctx->pc != 0x1477E8u) { return; }
    }
    ctx->pc = 0x1477E8u;
label_1477e8:
    // 0x1477e8: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1477e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1477ec: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x1477ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x1477f0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1477f0u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1477f4: 0x30424000  andi        $v0, $v0, 0x4000
    ctx->pc = 0x1477f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16384);
    // 0x1477f8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1477F8u;
    {
        const bool branch_taken_0x1477f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1477FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1477F8u;
            // 0x1477fc: 0x3c024000  lui         $v0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1477f8) {
            ctx->pc = 0x147808u;
            goto label_147808;
        }
    }
    ctx->pc = 0x147800u;
    // 0x147800: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x147800u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x147804: 0xac222010  sw          $v0, 0x2010($at)
    ctx->pc = 0x147804u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 2)); // MMIO: 0x10002010
label_147808:
    // 0x147808: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147808u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x14780c: 0x2a750400  slti        $s5, $s3, 0x400
    ctx->pc = 0x14780cu;
    SET_GPR_U64(ctx, 21, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x147810: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x147810u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x147814: 0x0  nop
    ctx->pc = 0x147814u;
    // NOP
label_147818:
    // 0x147818: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x147818u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x14781c: 0x0  nop
    ctx->pc = 0x14781cu;
    // NOP
    // 0x147820: 0x0  nop
    ctx->pc = 0x147820u;
    // NOP
    // 0x147824: 0x0  nop
    ctx->pc = 0x147824u;
    // NOP
    // 0x147828: 0x0  nop
    ctx->pc = 0x147828u;
    // NOP
    // 0x14782c: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x14782Cu;
    {
        const bool branch_taken_0x14782c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x14782c) {
            ctx->pc = 0x147818u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_147818;
        }
    }
    ctx->pc = 0x147834u;
    // 0x147834: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x147834u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147838: 0xc05148a  jal         func_145228
    ctx->pc = 0x147838u;
    SET_GPR_U32(ctx, 31, 0x147840u);
    ctx->pc = 0x14783Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147838u;
            // 0x14783c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145228u;
    if (runtime->hasFunction(0x145228u)) {
        auto targetFn = runtime->lookupFunction(0x145228u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147840u; }
        if (ctx->pc != 0x147840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147840u; }
        if (ctx->pc != 0x147840u) { return; }
    }
    ctx->pc = 0x147840u;
label_147840:
    // 0x147840: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x147840u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x147844: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x147844u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x147848: 0x34842010  ori         $a0, $a0, 0x2010
    ctx->pc = 0x147848u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8208);
    // 0x14784c: 0x0  nop
    ctx->pc = 0x14784cu;
    // NOP
label_147850:
    // 0x147850: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x147850u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x147854: 0x0  nop
    ctx->pc = 0x147854u;
    // NOP
    // 0x147858: 0x0  nop
    ctx->pc = 0x147858u;
    // NOP
    // 0x14785c: 0x0  nop
    ctx->pc = 0x14785cu;
    // NOP
    // 0x147860: 0x0  nop
    ctx->pc = 0x147860u;
    // NOP
    // 0x147864: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x147864u;
    {
        const bool branch_taken_0x147864 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x147864) {
            ctx->pc = 0x147850u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_147850;
        }
    }
    ctx->pc = 0x14786Cu;
    // 0x14786c: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x14786cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x147870: 0x3c110fff  lui         $s1, 0xFFF
    ctx->pc = 0x147870u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)4095 << 16));
    // 0x147874: 0x2621018  mult        $v0, $s3, $v0
    ctx->pc = 0x147874u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x147878: 0x3631ffff  ori         $s1, $s1, 0xFFFF
    ctx->pc = 0x147878u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)65535);
    // 0x14787c: 0x711824  and         $v1, $v1, $s1
    ctx->pc = 0x14787cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 17));
    // 0x147880: 0x3414ffff  ori         $s4, $zero, 0xFFFF
    ctx->pc = 0x147880u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x147884: 0xafa30024  sw          $v1, 0x24($sp)
    ctx->pc = 0x147884u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 3));
    // 0x147888: 0x282202b  sltu        $a0, $s4, $v0
    ctx->pc = 0x147888u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x14788c: 0x1080003a  beqz        $a0, . + 4 + (0x3A << 2)
    ctx->pc = 0x14788Cu;
    {
        const bool branch_taken_0x14788c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x147890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14788Cu;
            // 0x147890: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14788c) {
            ctx->pc = 0x147978u;
            goto label_147978;
        }
    }
    ctx->pc = 0x147894u;
    // 0x147894: 0x3c050014  lui         $a1, 0x14
    ctx->pc = 0x147894u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20 << 16));
    // 0x147898: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x147898u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x14789c: 0x24a576c8  addiu       $a1, $a1, 0x76C8
    ctx->pc = 0x14789cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 30408));
    // 0x1478a0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1478a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1478a4: 0xc0450d0  jal         func_114340
    ctx->pc = 0x1478A4u;
    SET_GPR_U32(ctx, 31, 0x1478ACu);
    ctx->pc = 0x1478A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1478A4u;
            // 0x1478a8: 0x27a70020  addiu       $a3, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114340u;
    if (runtime->hasFunction(0x114340u)) {
        auto targetFn = runtime->lookupFunction(0x114340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478ACu; }
        if (ctx->pc != 0x1478ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114340_0x114340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478ACu; }
        if (ctx->pc != 0x1478ACu) { return; }
    }
    ctx->pc = 0x1478ACu;
label_1478ac:
    // 0x1478ac: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1478acu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1478b0: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1478b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1478b4: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1478b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1478b8: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1478b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1478bc: 0x3442e010  ori         $v0, $v0, 0xE010
    ctx->pc = 0x1478bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57360);
    // 0x1478c0: 0xc04548e  jal         func_115238
    ctx->pc = 0x1478C0u;
    SET_GPR_U32(ctx, 31, 0x1478C8u);
    ctx->pc = 0x1478C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1478C0u;
            // 0x1478c4: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115238u;
    if (runtime->hasFunction(0x115238u)) {
        auto targetFn = runtime->lookupFunction(0x115238u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478C8u; }
        if (ctx->pc != 0x1478C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115238_0x115238(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478C8u; }
        if (ctx->pc != 0x1478C8u) { return; }
    }
    ctx->pc = 0x1478C8u;
label_1478c8:
    // 0x1478c8: 0xc047598  jal         func_11D660
    ctx->pc = 0x1478C8u;
    SET_GPR_U32(ctx, 31, 0x1478D0u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478D0u; }
        if (ctx->pc != 0x1478D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1478D0u; }
        if (ctx->pc != 0x1478D0u) { return; }
    }
    ctx->pc = 0x1478D0u;
label_1478d0:
    // 0x1478d0: 0x8fa50024  lw          $a1, 0x24($sp)
    ctx->pc = 0x1478d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1478d4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1478d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1478d8: 0x3463b410  ori         $v1, $v1, 0xB410
    ctx->pc = 0x1478d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46096);
    // 0x1478dc: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1478dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1478e0: 0xac650000  sw          $a1, 0x0($v1)
    ctx->pc = 0x1478e0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x1478e4: 0x3484b420  ori         $a0, $a0, 0xB420
    ctx->pc = 0x1478e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46112);
    // 0x1478e8: 0xac940000  sw          $s4, 0x0($a0)
    ctx->pc = 0x1478e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 20)); // MMIO: 0x10000000
    // 0x1478ec: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x1478ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x1478f0: 0x3463b400  ori         $v1, $v1, 0xB400
    ctx->pc = 0x1478f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46080);
    // 0x1478f4: 0x24040101  addiu       $a0, $zero, 0x101
    ctx->pc = 0x1478f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x1478f8: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1478f8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x1478fc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1478FCu;
    {
        const bool branch_taken_0x1478fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x147900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1478FCu;
            // 0x147900: 0x8fa20024  lw          $v0, 0x24($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1478fc) {
            ctx->pc = 0x147910u;
            goto label_147910;
        }
    }
    ctx->pc = 0x147904u;
    // 0x147904: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x147904u;
    SET_GPR_U32(ctx, 31, 0x14790Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14790Cu; }
        if (ctx->pc != 0x14790Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14790Cu; }
        if (ctx->pc != 0x14790Cu) { return; }
    }
    ctx->pc = 0x14790Cu;
label_14790c:
    // 0x14790c: 0x8fa20024  lw          $v0, 0x24($sp)
    ctx->pc = 0x14790cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_147910:
    // 0x147910: 0x3c03000f  lui         $v1, 0xF
    ctx->pc = 0x147910u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)15 << 16));
    // 0x147914: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x147914u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x147918: 0x3463fff0  ori         $v1, $v1, 0xFFF0
    ctx->pc = 0x147918u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65520);
    // 0x14791c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x14791cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x147920: 0x511024  and         $v0, $v0, $s1
    ctx->pc = 0x147920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 17));
    // 0x147924: 0x942023  subu        $a0, $a0, $s4
    ctx->pc = 0x147924u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 20)));
    // 0x147928: 0xafa20024  sw          $v0, 0x24($sp)
    ctx->pc = 0x147928u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
    // 0x14792c: 0x12a00007  beqz        $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x14792Cu;
    {
        const bool branch_taken_0x14792c = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        ctx->pc = 0x147930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14792Cu;
            // 0x147930: 0xafa40020  sw          $a0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14792c) {
            ctx->pc = 0x14794Cu;
            goto label_14794c;
        }
    }
    ctx->pc = 0x147934u;
    // 0x147934: 0x8e0500f0  lw          $a1, 0xF0($s0)
    ctx->pc = 0x147934u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x147938: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x147938u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14793c: 0xc051ca6  jal         func_147298
    ctx->pc = 0x14793Cu;
    SET_GPR_U32(ctx, 31, 0x147944u);
    ctx->pc = 0x147940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14793Cu;
            // 0x147940: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147298u;
    if (runtime->hasFunction(0x147298u)) {
        auto targetFn = runtime->lookupFunction(0x147298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147944u; }
        if (ctx->pc != 0x147944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147298_0x147298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147944u; }
        if (ctx->pc != 0x147944u) { return; }
    }
    ctx->pc = 0x147944u;
label_147944:
    // 0x147944: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x147944u;
    {
        const bool branch_taken_0x147944 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x147944) {
            ctx->pc = 0x14795Cu;
            goto label_14795c;
        }
    }
    ctx->pc = 0x14794Cu;
label_14794c:
    // 0x14794c: 0x8e0500f0  lw          $a1, 0xF0($s0)
    ctx->pc = 0x14794cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x147950: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x147950u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147954: 0xc051d42  jal         func_147508
    ctx->pc = 0x147954u;
    SET_GPR_U32(ctx, 31, 0x14795Cu);
    ctx->pc = 0x147958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147954u;
            // 0x147958: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147508u;
    if (runtime->hasFunction(0x147508u)) {
        auto targetFn = runtime->lookupFunction(0x147508u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14795Cu; }
        if (ctx->pc != 0x14795Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147508_0x147508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14795Cu; }
        if (ctx->pc != 0x14795Cu) { return; }
    }
    ctx->pc = 0x14795Cu;
label_14795c:
    // 0x14795c: 0xc045474  jal         func_1151D0
    ctx->pc = 0x14795Cu;
    SET_GPR_U32(ctx, 31, 0x147964u);
    ctx->pc = 0x147960u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14795Cu;
            // 0x147960: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1151D0u;
    if (runtime->hasFunction(0x1151D0u)) {
        auto targetFn = runtime->lookupFunction(0x1151D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147964u; }
        if (ctx->pc != 0x147964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001151D0_0x1151d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147964u; }
        if (ctx->pc != 0x147964u) { return; }
    }
    ctx->pc = 0x147964u;
label_147964:
    // 0x147964: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x147964u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147968: 0xc0450d4  jal         func_114350
    ctx->pc = 0x147968u;
    SET_GPR_U32(ctx, 31, 0x147970u);
    ctx->pc = 0x14796Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147968u;
            // 0x14796c: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114350u;
    if (runtime->hasFunction(0x114350u)) {
        auto targetFn = runtime->lookupFunction(0x114350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147970u; }
        if (ctx->pc != 0x147970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114350_0x114350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147970u; }
        if (ctx->pc != 0x147970u) { return; }
    }
    ctx->pc = 0x147970u;
label_147970:
    // 0x147970: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x147970u;
    {
        const bool branch_taken_0x147970 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x147974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147970u;
            // 0x147974: 0x8e040870  lw          $a0, 0x870($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147970) {
            ctx->pc = 0x1479F4u;
            goto label_1479f4;
        }
    }
    ctx->pc = 0x147978u;
label_147978:
    // 0x147978: 0xc047598  jal         func_11D660
    ctx->pc = 0x147978u;
    SET_GPR_U32(ctx, 31, 0x147980u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147980u; }
        if (ctx->pc != 0x147980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147980u; }
        if (ctx->pc != 0x147980u) { return; }
    }
    ctx->pc = 0x147980u;
label_147980:
    // 0x147980: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x147980u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x147984: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147984u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x147988: 0x3463b410  ori         $v1, $v1, 0xB410
    ctx->pc = 0x147988u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46096);
    // 0x14798c: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x14798cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x147990: 0xb12824  and         $a1, $a1, $s1
    ctx->pc = 0x147990u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 17));
    // 0x147994: 0x34c6b420  ori         $a2, $a2, 0xB420
    ctx->pc = 0x147994u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)46112);
    // 0x147998: 0xac650000  sw          $a1, 0x0($v1)
    ctx->pc = 0x147998u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x14799c: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x14799cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1479a0: 0x3484b400  ori         $a0, $a0, 0xB400
    ctx->pc = 0x1479a0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46080);
    // 0x1479a4: 0x24050101  addiu       $a1, $zero, 0x101
    ctx->pc = 0x1479a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x1479a8: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x1479a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1479ac: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x1479acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x1479b0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1479B0u;
    {
        const bool branch_taken_0x1479b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1479B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1479B0u;
            // 0x1479b4: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1479b0) {
            ctx->pc = 0x1479C0u;
            goto label_1479c0;
        }
    }
    ctx->pc = 0x1479B8u;
    // 0x1479b8: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1479B8u;
    SET_GPR_U32(ctx, 31, 0x1479C0u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479C0u; }
        if (ctx->pc != 0x1479C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479C0u; }
        if (ctx->pc != 0x1479C0u) { return; }
    }
    ctx->pc = 0x1479C0u;
label_1479c0:
    // 0x1479c0: 0x12a00007  beqz        $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x1479C0u;
    {
        const bool branch_taken_0x1479c0 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        ctx->pc = 0x1479C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1479C0u;
            // 0x1479c4: 0xafa00020  sw          $zero, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1479c0) {
            ctx->pc = 0x1479E0u;
            goto label_1479e0;
        }
    }
    ctx->pc = 0x1479C8u;
    // 0x1479c8: 0x8e0500f0  lw          $a1, 0xF0($s0)
    ctx->pc = 0x1479c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x1479cc: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1479ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1479d0: 0xc051ca6  jal         func_147298
    ctx->pc = 0x1479D0u;
    SET_GPR_U32(ctx, 31, 0x1479D8u);
    ctx->pc = 0x1479D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1479D0u;
            // 0x1479d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147298u;
    if (runtime->hasFunction(0x147298u)) {
        auto targetFn = runtime->lookupFunction(0x147298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479D8u; }
        if (ctx->pc != 0x1479D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147298_0x147298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479D8u; }
        if (ctx->pc != 0x1479D8u) { return; }
    }
    ctx->pc = 0x1479D8u;
label_1479d8:
    // 0x1479d8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1479D8u;
    {
        const bool branch_taken_0x1479d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1479DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1479D8u;
            // 0x1479dc: 0x8e040870  lw          $a0, 0x870($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1479d8) {
            ctx->pc = 0x1479F4u;
            goto label_1479f4;
        }
    }
    ctx->pc = 0x1479E0u;
label_1479e0:
    // 0x1479e0: 0x8e0500f0  lw          $a1, 0xF0($s0)
    ctx->pc = 0x1479e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x1479e4: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1479e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1479e8: 0xc051d42  jal         func_147508
    ctx->pc = 0x1479E8u;
    SET_GPR_U32(ctx, 31, 0x1479F0u);
    ctx->pc = 0x1479ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1479E8u;
            // 0x1479ec: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147508u;
    if (runtime->hasFunction(0x147508u)) {
        auto targetFn = runtime->lookupFunction(0x147508u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479F0u; }
        if (ctx->pc != 0x1479F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147508_0x147508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1479F0u; }
        if (ctx->pc != 0x1479F0u) { return; }
    }
    ctx->pc = 0x1479F0u;
label_1479f0:
    // 0x1479f0: 0x8e040870  lw          $a0, 0x870($s0)
    ctx->pc = 0x1479f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2160)));
label_1479f4:
    // 0x1479f4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1479f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1479f8: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1479f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1479fc: 0xc051fda  jal         func_147F68
    ctx->pc = 0x1479FCu;
    SET_GPR_U32(ctx, 31, 0x147A04u);
    ctx->pc = 0x147A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1479FCu;
            // 0x147a00: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F68u;
    if (runtime->hasFunction(0x147F68u)) {
        auto targetFn = runtime->lookupFunction(0x147F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147A04u; }
        if (ctx->pc != 0x147A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147A04u; }
        if (ctx->pc != 0x147A04u) { return; }
    }
    ctx->pc = 0x147A04u;
label_147a04:
    // 0x147a04: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x147a04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x147a08: 0xdfb50080  ld          $s5, 0x80($sp)
    ctx->pc = 0x147a08u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x147a0c: 0xdfb40070  ld          $s4, 0x70($sp)
    ctx->pc = 0x147a0cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x147a10: 0xdfb30060  ld          $s3, 0x60($sp)
    ctx->pc = 0x147a10u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x147a14: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x147a14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x147a18: 0xdfb10040  ld          $s1, 0x40($sp)
    ctx->pc = 0x147a18u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x147a1c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x147a1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x147a20: 0x3e00008  jr          $ra
    ctx->pc = 0x147A20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147A20u;
            // 0x147a24: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1477E8u: goto label_1477e8;
            case 0x147808u: goto label_147808;
            case 0x147818u: goto label_147818;
            case 0x147840u: goto label_147840;
            case 0x147850u: goto label_147850;
            case 0x1478ACu: goto label_1478ac;
            case 0x1478C8u: goto label_1478c8;
            case 0x1478D0u: goto label_1478d0;
            case 0x14790Cu: goto label_14790c;
            case 0x147910u: goto label_147910;
            case 0x147944u: goto label_147944;
            case 0x14794Cu: goto label_14794c;
            case 0x14795Cu: goto label_14795c;
            case 0x147964u: goto label_147964;
            case 0x147970u: goto label_147970;
            case 0x147978u: goto label_147978;
            case 0x147980u: goto label_147980;
            case 0x1479C0u: goto label_1479c0;
            case 0x1479D8u: goto label_1479d8;
            case 0x1479E0u: goto label_1479e0;
            case 0x1479F0u: goto label_1479f0;
            case 0x1479F4u: goto label_1479f4;
            case 0x147A04u: goto label_147a04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x147A28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
