#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001453C0
// Address: 0x1453c0 - 0x145548
void sub_001453C0_0x1453c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001453C0_0x1453c0");
#endif

    switch (ctx->pc) {
        case 0x145478u: goto label_145478;
        case 0x145488u: goto label_145488;
        case 0x1454b8u: goto label_1454b8;
        case 0x1454ecu: goto label_1454ec;
        default: break;
    }

    ctx->pc = 0x1453c0u;

    // 0x1453c0: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x1453c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1453c4: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1453c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1453c8: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x1453c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x1453cc: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x1453ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x1453d0: 0xffbe00a0  sd          $fp, 0xA0($sp)
    ctx->pc = 0x1453d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x1453d4: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1453d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1453d8: 0xffb70090  sd          $s7, 0x90($sp)
    ctx->pc = 0x1453d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 23));
    // 0x1453dc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1453dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1453e0: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x1453e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x1453e4: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x1453e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x1453e8: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x1453e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x1453ec: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x1453ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x1453f0: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x1453f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x1453f4: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1453f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1453f8: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x1453f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x1453fc: 0xdc540000  ld          $s4, 0x0($v0)
    ctx->pc = 0x1453fcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x145400: 0x6810044  bgez        $s4, . + 4 + (0x44 << 2)
    ctx->pc = 0x145400u;
    {
        const bool branch_taken_0x145400 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x145404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145400u;
            // 0x145404: 0x280102d  daddu       $v0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145400) {
            ctx->pc = 0x145514u;
            goto label_145514;
        }
    }
    ctx->pc = 0x145408u;
    // 0x145408: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x145408u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x14540c: 0x34422010  ori         $v0, $v0, 0x2010
    ctx->pc = 0x14540cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8208);
    // 0x145410: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x145410u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x145414: 0x30634000  andi        $v1, $v1, 0x4000
    ctx->pc = 0x145414u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16384);
    // 0x145418: 0x1460003e  bnez        $v1, . + 4 + (0x3E << 2)
    ctx->pc = 0x145418u;
    {
        const bool branch_taken_0x145418 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x14541Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145418u;
            // 0x14541c: 0x280102d  daddu       $v0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145418) {
            ctx->pc = 0x145514u;
            goto label_145514;
        }
    }
    ctx->pc = 0x145420u;
    // 0x145420: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x145420u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x145424: 0x3c131000  lui         $s3, 0x1000
    ctx->pc = 0x145424u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)4096 << 16));
    // 0x145428: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x145428u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x14542c: 0x3c111000  lui         $s1, 0x1000
    ctx->pc = 0x14542cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)4096 << 16));
    // 0x145430: 0x3442b420  ori         $v0, $v0, 0xB420
    ctx->pc = 0x145430u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46112);
    // 0x145434: 0x3c151000  lui         $s5, 0x1000
    ctx->pc = 0x145434u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)4096 << 16));
    // 0x145438: 0x3c161000  lui         $s6, 0x1000
    ctx->pc = 0x145438u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)4096 << 16));
    // 0x14543c: 0x3c17fffe  lui         $s7, 0xFFFE
    ctx->pc = 0x14543cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)65534 << 16));
    // 0x145440: 0x3c1e1000  lui         $fp, 0x1000
    ctx->pc = 0x145440u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)4096 << 16));
    // 0x145444: 0x3c121000  lui         $s2, 0x1000
    ctx->pc = 0x145444u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)4096 << 16));
    // 0x145448: 0x3c101000  lui         $s0, 0x1000
    ctx->pc = 0x145448u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)4096 << 16));
    // 0x14544c: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x14544cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x145450: 0x3673f590  ori         $s3, $s3, 0xF590
    ctx->pc = 0x145450u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)62864);
    // 0x145454: 0x3631f520  ori         $s1, $s1, 0xF520
    ctx->pc = 0x145454u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)62752);
    // 0x145458: 0x36b5b400  ori         $s5, $s5, 0xB400
    ctx->pc = 0x145458u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) | (uint64_t)(uint16_t)46080);
    // 0x14545c: 0x36d6b000  ori         $s6, $s6, 0xB000
    ctx->pc = 0x14545cu;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | (uint64_t)(uint16_t)45056);
    // 0x145460: 0x36f7ffff  ori         $s7, $s7, 0xFFFF
    ctx->pc = 0x145460u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)65535);
    // 0x145464: 0x37deb020  ori         $fp, $fp, 0xB020
    ctx->pc = 0x145464u;
    SET_GPR_U64(ctx, 30, GPR_U64(ctx, 30) | (uint64_t)(uint16_t)45088);
    // 0x145468: 0x36522010  ori         $s2, $s2, 0x2010
    ctx->pc = 0x145468u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)8208);
    // 0x14546c: 0x36102000  ori         $s0, $s0, 0x2000
    ctx->pc = 0x14546cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)8192);
    // 0x145470: 0x8ca210a0  lw          $v0, 0x10A0($a1)
    ctx->pc = 0x145470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4256)));
    // 0x145474: 0x0  nop
    ctx->pc = 0x145474u;
    // NOP
label_145478:
    // 0x145478: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x145478u;
    {
        const bool branch_taken_0x145478 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14547Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145478u;
            // 0x14547c: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145478) {
            ctx->pc = 0x1454D4u;
            goto label_1454d4;
        }
    }
    ctx->pc = 0x145480u;
    // 0x145480: 0xc047598  jal         func_11D660
    ctx->pc = 0x145480u;
    SET_GPR_U32(ctx, 31, 0x145488u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145488u; }
        if (ctx->pc != 0x145488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145488u; }
        if (ctx->pc != 0x145488u) { return; }
    }
    ctx->pc = 0x145488u;
label_145488:
    // 0x145488: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x145488u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14548c: 0x3c040001  lui         $a0, 0x1
    ctx->pc = 0x14548cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x145490: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x145490u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x145494: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x145494u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x145498: 0xaea00000  sw          $zero, 0x0($s5)
    ctx->pc = 0x145498u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x14549c: 0xaec00000  sw          $zero, 0x0($s6)
    ctx->pc = 0x14549cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 0));
    // 0x1454a0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1454a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1454a4: 0x771824  and         $v1, $v1, $s7
    ctx->pc = 0x1454a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 23));
    // 0x1454a8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1454A8u;
    {
        const bool branch_taken_0x1454a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1454ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1454A8u;
            // 0x1454ac: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1454a8) {
            ctx->pc = 0x1454B8u;
            goto label_1454b8;
        }
    }
    ctx->pc = 0x1454B0u;
    // 0x1454b0: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1454B0u;
    SET_GPR_U32(ctx, 31, 0x1454B8u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1454B8u; }
        if (ctx->pc != 0x1454B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1454B8u; }
        if (ctx->pc != 0x1454B8u) { return; }
    }
    ctx->pc = 0x1454B8u;
label_1454b8:
    // 0x1454b8: 0xafc00000  sw          $zero, 0x0($fp)
    ctx->pc = 0x1454b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x1454bc: 0x3c044000  lui         $a0, 0x4000
    ctx->pc = 0x1454bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16384 << 16));
    // 0x1454c0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1454c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1454c4: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1454c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1454c8: 0xae440000  sw          $a0, 0x0($s2)
    ctx->pc = 0x1454c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x1454cc: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1454CCu;
    {
        const bool branch_taken_0x1454cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1454D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1454CCu;
            // 0x1454d0: 0x280102d  daddu       $v0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1454cc) {
            ctx->pc = 0x145514u;
            goto label_145514;
        }
    }
    ctx->pc = 0x1454D4u;
label_1454d4:
    // 0x1454d4: 0x28421389  slti        $v0, $v0, 0x1389
    ctx->pc = 0x1454d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5001) ? 1 : 0);
    // 0x1454d8: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1454D8u;
    {
        const bool branch_taken_0x1454d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1454DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1454D8u;
            // 0x1454dc: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1454d8) {
            ctx->pc = 0x1454F4u;
            goto label_1454f4;
        }
    }
    ctx->pc = 0x1454E0u;
    // 0x1454e0: 0x8ca40870  lw          $a0, 0x870($a1)
    ctx->pc = 0x1454e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 2160)));
    // 0x1454e4: 0xc051ff8  jal         func_147FE0
    ctx->pc = 0x1454E4u;
    SET_GPR_U32(ctx, 31, 0x1454ECu);
    ctx->pc = 0x1454E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1454E4u;
            // 0x1454e8: 0x7fa50010  sq          $a1, 0x10($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147FE0u;
    if (runtime->hasFunction(0x147FE0u)) {
        auto targetFn = runtime->lookupFunction(0x147FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1454ECu; }
        if (ctx->pc != 0x1454ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1454ECu; }
        if (ctx->pc != 0x1454ECu) { return; }
    }
    ctx->pc = 0x1454ECu;
label_1454ec:
    // 0x1454ec: 0x7ba50010  lq          $a1, 0x10($sp)
    ctx->pc = 0x1454ecu;
    SET_GPR_VEC(ctx, 5, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1454f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1454f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1454f4:
    // 0x1454f4: 0xde140000  ld          $s4, 0x0($s0)
    ctx->pc = 0x1454f4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1454f8: 0x6810006  bgez        $s4, . + 4 + (0x6 << 2)
    ctx->pc = 0x1454F8u;
    {
        const bool branch_taken_0x1454f8 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x1454FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1454F8u;
            // 0x1454fc: 0x280102d  daddu       $v0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1454f8) {
            ctx->pc = 0x145514u;
            goto label_145514;
        }
    }
    ctx->pc = 0x145500u;
    // 0x145500: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x145500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x145504: 0x30424000  andi        $v0, $v0, 0x4000
    ctx->pc = 0x145504u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16384);
    // 0x145508: 0x5040ffdb  beql        $v0, $zero, . + 4 + (-0x25 << 2)
    ctx->pc = 0x145508u;
    {
        const bool branch_taken_0x145508 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x145508) {
            ctx->pc = 0x14550Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x145508u;
            // 0x14550c: 0x8ca210a0  lw          $v0, 0x10A0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4256)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x145478u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_145478;
        }
    }
    ctx->pc = 0x145510u;
    // 0x145510: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x145510u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_145514:
    // 0x145514: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x145514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x145518: 0xdfbe00a0  ld          $fp, 0xA0($sp)
    ctx->pc = 0x145518u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x14551c: 0xdfb70090  ld          $s7, 0x90($sp)
    ctx->pc = 0x14551cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x145520: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x145520u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x145524: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x145524u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x145528: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x145528u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x14552c: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x14552cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x145530: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x145530u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x145534: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x145534u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x145538: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x145538u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14553c: 0x3e00008  jr          $ra
    ctx->pc = 0x14553Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14553Cu;
            // 0x145540: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145478u: goto label_145478;
            case 0x145488u: goto label_145488;
            case 0x1454B8u: goto label_1454b8;
            case 0x1454D4u: goto label_1454d4;
            case 0x1454ECu: goto label_1454ec;
            case 0x1454F4u: goto label_1454f4;
            case 0x145514u: goto label_145514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145544u;
    // 0x145544: 0x0  nop
    ctx->pc = 0x145544u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
