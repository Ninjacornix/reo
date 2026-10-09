#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00147508
// Address: 0x147508 - 0x1477a0
void sub_00147508_0x147508(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00147508_0x147508");
#endif

    switch (ctx->pc) {
        case 0x147578u: goto label_147578;
        case 0x1475a8u: goto label_1475a8;
        case 0x1475c4u: goto label_1475c4;
        case 0x1475ccu: goto label_1475cc;
        case 0x147614u: goto label_147614;
        case 0x14763cu: goto label_14763c;
        case 0x147648u: goto label_147648;
        case 0x147678u: goto label_147678;
        case 0x147680u: goto label_147680;
        case 0x1476a4u: goto label_1476a4;
        case 0x1476b0u: goto label_1476b0;
        default: break;
    }

    ctx->pc = 0x147508u;

    // 0x147508: 0x240703ff  addiu       $a3, $zero, 0x3FF
    ctx->pc = 0x147508u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1023));
    // 0x14750c: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x14750cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x147510: 0xc7001a  div         $zero, $a2, $a3
    ctx->pc = 0x147510u;
    { int32_t divisor = GPR_S32(ctx, 7);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x147514: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x147514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x147518: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x147518u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x14751c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x14751cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147520: 0x3442fc00  ori         $v0, $v0, 0xFC00
    ctx->pc = 0x147520u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64512);
    // 0x147524: 0x3c030fff  lui         $v1, 0xFFF
    ctx->pc = 0x147524u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4095 << 16));
    // 0x147528: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x147528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x14752c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x14752cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x147530: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x147530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x147534: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x147534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x147538: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x147538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x14753c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x14753cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x147540: 0x50e00001  beql        $a3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x147540u;
    {
        const bool branch_taken_0x147540 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x147540) {
            ctx->pc = 0x147544u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x147540u;
            // 0x147544: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x147548u;
            goto label_147548;
        }
    }
    ctx->pc = 0x147548u;
label_147548:
    // 0x147548: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147548u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x14754c: 0xafa60028  sw          $a2, 0x28($sp)
    ctx->pc = 0x14754cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 6));
    // 0x147550: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x147550u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147554: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x147554u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x147558: 0x27a70020  addiu       $a3, $sp, 0x20
    ctx->pc = 0x147558u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x14755c: 0xafa00024  sw          $zero, 0x24($sp)
    ctx->pc = 0x14755cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0x147560: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x147560u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x147564: 0xafa00020  sw          $zero, 0x20($sp)
    ctx->pc = 0x147564u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    // 0x147568: 0x4012  mflo        $t0
    ctx->pc = 0x147568u;
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x14756c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x14756cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x147570: 0xafa80030  sw          $t0, 0x30($sp)
    ctx->pc = 0x147570u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 8));
    // 0x147574: 0x0  nop
    ctx->pc = 0x147574u;
    // NOP
label_147578:
    // 0x147578: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x147578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14757c: 0x0  nop
    ctx->pc = 0x14757cu;
    // NOP
    // 0x147580: 0x0  nop
    ctx->pc = 0x147580u;
    // NOP
    // 0x147584: 0x0  nop
    ctx->pc = 0x147584u;
    // NOP
    // 0x147588: 0x0  nop
    ctx->pc = 0x147588u;
    // NOP
    // 0x14758c: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x14758Cu;
    {
        const bool branch_taken_0x14758c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x14758c) {
            ctx->pc = 0x147578u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_147578;
        }
    }
    ctx->pc = 0x147594u;
    // 0x147594: 0x3c050014  lui         $a1, 0x14
    ctx->pc = 0x147594u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20 << 16));
    // 0x147598: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x147598u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x14759c: 0x24a573c0  addiu       $a1, $a1, 0x73C0
    ctx->pc = 0x14759cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29632));
    // 0x1475a0: 0xc0450d0  jal         func_114340
    ctx->pc = 0x1475A0u;
    SET_GPR_U32(ctx, 31, 0x1475A8u);
    ctx->pc = 0x1475A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1475A0u;
            // 0x1475a4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114340u;
    if (runtime->hasFunction(0x114340u)) {
        auto targetFn = runtime->lookupFunction(0x114340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475A8u; }
        if (ctx->pc != 0x1475A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114340_0x114340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475A8u; }
        if (ctx->pc != 0x1475A8u) { return; }
    }
    ctx->pc = 0x1475A8u;
label_1475a8:
    // 0x1475a8: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1475a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1475ac: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1475acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1475b0: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1475b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1475b4: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1475b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1475b8: 0x3442e010  ori         $v0, $v0, 0xE010
    ctx->pc = 0x1475b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57360);
    // 0x1475bc: 0xc04548e  jal         func_115238
    ctx->pc = 0x1475BCu;
    SET_GPR_U32(ctx, 31, 0x1475C4u);
    ctx->pc = 0x1475C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1475BCu;
            // 0x1475c0: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115238u;
    if (runtime->hasFunction(0x115238u)) {
        auto targetFn = runtime->lookupFunction(0x115238u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475C4u; }
        if (ctx->pc != 0x1475C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115238_0x115238(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475C4u; }
        if (ctx->pc != 0x1475C4u) { return; }
    }
    ctx->pc = 0x1475C4u;
label_1475c4:
    // 0x1475c4: 0xc047598  jal         func_11D660
    ctx->pc = 0x1475C4u;
    SET_GPR_U32(ctx, 31, 0x1475CCu);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475CCu; }
        if (ctx->pc != 0x1475CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475CCu; }
        if (ctx->pc != 0x1475CCu) { return; }
    }
    ctx->pc = 0x1475CCu;
label_1475cc:
    // 0x1475cc: 0x3c030fff  lui         $v1, 0xFFF
    ctx->pc = 0x1475ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4095 << 16));
    // 0x1475d0: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1475d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1475d4: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x1475d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x1475d8: 0x3484b010  ori         $a0, $a0, 0xB010
    ctx->pc = 0x1475d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45072);
    // 0x1475dc: 0x2031824  and         $v1, $s0, $v1
    ctx->pc = 0x1475dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x1475e0: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x1475e0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x1475e4: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x1475e4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1475e8: 0x34a5b020  ori         $a1, $a1, 0xB020
    ctx->pc = 0x1475e8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)45088);
    // 0x1475ec: 0x3403ffc0  ori         $v1, $zero, 0xFFC0
    ctx->pc = 0x1475ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x1475f0: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x1475f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x1475f4: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1475f4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1475f8: 0x3484b000  ori         $a0, $a0, 0xB000
    ctx->pc = 0x1475f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)45056);
    // 0x1475fc: 0x24030100  addiu       $v1, $zero, 0x100
    ctx->pc = 0x1475fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x147600: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x147600u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x147604: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x147604u;
    {
        const bool branch_taken_0x147604 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x147608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147604u;
            // 0x147608: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147604) {
            ctx->pc = 0x147618u;
            goto label_147618;
        }
    }
    ctx->pc = 0x14760Cu;
    // 0x14760c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x14760Cu;
    SET_GPR_U32(ctx, 31, 0x147614u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147614u; }
        if (ctx->pc != 0x147614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147614u; }
        if (ctx->pc != 0x147614u) { return; }
    }
    ctx->pc = 0x147614u;
label_147614:
    // 0x147614: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x147614u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
label_147618:
    // 0x147618: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x147618u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x14761c: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x14761cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x147620: 0x346303ff  ori         $v1, $v1, 0x3FF
    ctx->pc = 0x147620u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1023);
    // 0x147624: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x147624u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x147628: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x147628u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x14762c: 0x8e240870  lw          $a0, 0x870($s1)
    ctx->pc = 0x14762cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x147630: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x147630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147634: 0xc051fda  jal         func_147F68
    ctx->pc = 0x147634u;
    SET_GPR_U32(ctx, 31, 0x14763Cu);
    ctx->pc = 0x147638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147634u;
            // 0x147638: 0xafa60000  sw          $a2, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147F68u;
    if (runtime->hasFunction(0x147F68u)) {
        auto targetFn = runtime->lookupFunction(0x147F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14763Cu; }
        if (ctx->pc != 0x14763Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14763Cu; }
        if (ctx->pc != 0x14763Cu) { return; }
    }
    ctx->pc = 0x14763Cu;
label_14763c:
    // 0x14763c: 0x8fa40024  lw          $a0, 0x24($sp)
    ctx->pc = 0x14763cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x147640: 0x8fa30030  lw          $v1, 0x30($sp)
    ctx->pc = 0x147640u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x147644: 0x0  nop
    ctx->pc = 0x147644u;
    // NOP
label_147648:
    // 0x147648: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x147648u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14764c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x14764cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x147650: 0x0  nop
    ctx->pc = 0x147650u;
    // NOP
    // 0x147654: 0x0  nop
    ctx->pc = 0x147654u;
    // NOP
    // 0x147658: 0x0  nop
    ctx->pc = 0x147658u;
    // NOP
    // 0x14765c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x14765Cu;
    {
        const bool branch_taken_0x14765c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x14765c) {
            ctx->pc = 0x147648u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_147648;
        }
    }
    ctx->pc = 0x147664u;
    // 0x147664: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x147664u;
    {
        const bool branch_taken_0x147664 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x147668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147664u;
            // 0x147668: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147664) {
            ctx->pc = 0x147678u;
            goto label_147678;
        }
    }
    ctx->pc = 0x14766Cu;
    // 0x14766c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x14766cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x147670: 0xc05221c  jal         func_148870
    ctx->pc = 0x147670u;
    SET_GPR_U32(ctx, 31, 0x147678u);
    ctx->pc = 0x147674u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147670u;
            // 0x147674: 0x24a5dff0  addiu       $a1, $a1, -0x2010 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147678u; }
        if (ctx->pc != 0x147678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147678u; }
        if (ctx->pc != 0x147678u) { return; }
    }
    ctx->pc = 0x147678u;
label_147678:
    // 0x147678: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x147678u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x14767c: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x14767cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
label_147680:
    // 0x147680: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x147680u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x147684: 0x0  nop
    ctx->pc = 0x147684u;
    // NOP
    // 0x147688: 0x0  nop
    ctx->pc = 0x147688u;
    // NOP
    // 0x14768c: 0x0  nop
    ctx->pc = 0x14768cu;
    // NOP
    // 0x147690: 0x0  nop
    ctx->pc = 0x147690u;
    // NOP
    // 0x147694: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x147694u;
    {
        const bool branch_taken_0x147694 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x147694) {
            ctx->pc = 0x147680u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_147680;
        }
    }
    ctx->pc = 0x14769Cu;
    // 0x14769c: 0xc045474  jal         func_1151D0
    ctx->pc = 0x14769Cu;
    SET_GPR_U32(ctx, 31, 0x1476A4u);
    ctx->pc = 0x1476A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14769Cu;
            // 0x1476a0: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1151D0u;
    if (runtime->hasFunction(0x1151D0u)) {
        auto targetFn = runtime->lookupFunction(0x1151D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1476A4u; }
        if (ctx->pc != 0x1476A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001151D0_0x1151d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1476A4u; }
        if (ctx->pc != 0x1476A4u) { return; }
    }
    ctx->pc = 0x1476A4u;
label_1476a4:
    // 0x1476a4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1476a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1476a8: 0xc0450d4  jal         func_114350
    ctx->pc = 0x1476A8u;
    SET_GPR_U32(ctx, 31, 0x1476B0u);
    ctx->pc = 0x1476ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1476A8u;
            // 0x1476ac: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114350u;
    if (runtime->hasFunction(0x114350u)) {
        auto targetFn = runtime->lookupFunction(0x114350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1476B0u; }
        if (ctx->pc != 0x1476B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114350_0x114350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1476B0u; }
        if (ctx->pc != 0x1476B0u) { return; }
    }
    ctx->pc = 0x1476B0u;
label_1476b0:
    // 0x1476b0: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1476b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1476b4: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x1476b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1476b8: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x1476b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1476bc: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x1476bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1476c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1476C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1476C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1476C0u;
            // 0x1476c4: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147548u: goto label_147548;
            case 0x147578u: goto label_147578;
            case 0x1475A8u: goto label_1475a8;
            case 0x1475C4u: goto label_1475c4;
            case 0x1475CCu: goto label_1475cc;
            case 0x147614u: goto label_147614;
            case 0x147618u: goto label_147618;
            case 0x14763Cu: goto label_14763c;
            case 0x147648u: goto label_147648;
            case 0x147678u: goto label_147678;
            case 0x147680u: goto label_147680;
            case 0x1476A4u: goto label_1476a4;
            case 0x1476B0u: goto label_1476b0;
            case 0x1476F8u: goto label_1476f8;
            case 0x14775Cu: goto label_14775c;
            case 0x14778Cu: goto label_14778c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1476C8u;
    // 0x1476c8: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1476c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1476cc: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1476ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1476d0: 0x3442e010  ori         $v0, $v0, 0xE010
    ctx->pc = 0x1476d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)57360);
    // 0x1476d4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1476d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1476d8: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1476d8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1476dc: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1476dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1476e0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1476E0u;
    {
        const bool branch_taken_0x1476e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1476E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1476E0u;
            // 0x1476e4: 0x3407ffff  ori         $a3, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1476e0) {
            ctx->pc = 0x1476F8u;
            goto label_1476f8;
        }
    }
    ctx->pc = 0x1476E8u;
    // 0x1476e8: 0xf  sync
    ctx->pc = 0x1476e8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1476ec: 0x42000038  ei
    ctx->pc = 0x1476ecu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1476f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1476F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1476F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1476F0u;
            // 0x1476f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147548u: goto label_147548;
            case 0x147578u: goto label_147578;
            case 0x1475A8u: goto label_1475a8;
            case 0x1475C4u: goto label_1475c4;
            case 0x1475CCu: goto label_1475cc;
            case 0x147614u: goto label_147614;
            case 0x147618u: goto label_147618;
            case 0x14763Cu: goto label_14763c;
            case 0x147648u: goto label_147648;
            case 0x147678u: goto label_147678;
            case 0x147680u: goto label_147680;
            case 0x1476A4u: goto label_1476a4;
            case 0x1476B0u: goto label_1476b0;
            case 0x1476F8u: goto label_1476f8;
            case 0x14775Cu: goto label_14775c;
            case 0x14778Cu: goto label_14778c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1476F8u;
label_1476f8:
    // 0x1476f8: 0xe2102b  sltu        $v0, $a3, $v0
    ctx->pc = 0x1476f8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1476fc: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1476FCu;
    {
        const bool branch_taken_0x1476fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x147700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1476FCu;
            // 0x147700: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1476fc) {
            ctx->pc = 0x14775Cu;
            goto label_14775c;
        }
    }
    ctx->pc = 0x147704u;
    // 0x147704: 0x8cc40004  lw          $a0, 0x4($a2)
    ctx->pc = 0x147704u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x147708: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x147708u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x14770c: 0x3442b410  ori         $v0, $v0, 0xB410
    ctx->pc = 0x14770cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46096);
    // 0x147710: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x147710u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x147714: 0x3463b420  ori         $v1, $v1, 0xB420
    ctx->pc = 0x147714u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46112);
    // 0x147718: 0xac670000  sw          $a3, 0x0($v1)
    ctx->pc = 0x147718u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 7));
    // 0x14771c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x14771cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x147720: 0x3442b400  ori         $v0, $v0, 0xB400
    ctx->pc = 0x147720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46080);
    // 0x147724: 0x24030101  addiu       $v1, $zero, 0x101
    ctx->pc = 0x147724u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x147728: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x147728u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x14772c: 0x3c05000f  lui         $a1, 0xF
    ctx->pc = 0x14772cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)15 << 16));
    // 0x147730: 0x34a5fff0  ori         $a1, $a1, 0xFFF0
    ctx->pc = 0x147730u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65520);
    // 0x147734: 0x3c040fff  lui         $a0, 0xFFF
    ctx->pc = 0x147734u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4095 << 16));
    // 0x147738: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x147738u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x14773c: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x14773cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x147740: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x147740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x147744: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x147744u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x147748: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x147748u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x14774c: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x14774cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x147750: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x147750u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x147754: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x147754u;
    {
        const bool branch_taken_0x147754 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x147758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147754u;
            // 0x147758: 0xacc30004  sw          $v1, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147754) {
            ctx->pc = 0x14778Cu;
            goto label_14778c;
        }
    }
    ctx->pc = 0x14775Cu;
label_14775c:
    // 0x14775c: 0x8cc40004  lw          $a0, 0x4($a2)
    ctx->pc = 0x14775cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x147760: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x147760u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x147764: 0x3442b410  ori         $v0, $v0, 0xB410
    ctx->pc = 0x147764u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46096);
    // 0x147768: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x147768u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x14776c: 0x3463b420  ori         $v1, $v1, 0xB420
    ctx->pc = 0x14776cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)46112);
    // 0x147770: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x147770u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x147774: 0x24050101  addiu       $a1, $zero, 0x101
    ctx->pc = 0x147774u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x147778: 0x8cc40000  lw          $a0, 0x0($a2)
    ctx->pc = 0x147778u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14777c: 0x3442b400  ori         $v0, $v0, 0xB400
    ctx->pc = 0x14777cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)46080);
    // 0x147780: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x147780u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x147784: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x147784u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x147788: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x147788u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_14778c:
    // 0x14778c: 0xf  sync
    ctx->pc = 0x14778cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x147790: 0x42000038  ei
    ctx->pc = 0x147790u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x147794: 0x3e00008  jr          $ra
    ctx->pc = 0x147794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147794u;
            // 0x147798: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147548u: goto label_147548;
            case 0x147578u: goto label_147578;
            case 0x1475A8u: goto label_1475a8;
            case 0x1475C4u: goto label_1475c4;
            case 0x1475CCu: goto label_1475cc;
            case 0x147614u: goto label_147614;
            case 0x147618u: goto label_147618;
            case 0x14763Cu: goto label_14763c;
            case 0x147648u: goto label_147648;
            case 0x147678u: goto label_147678;
            case 0x147680u: goto label_147680;
            case 0x1476A4u: goto label_1476a4;
            case 0x1476B0u: goto label_1476b0;
            case 0x1476F8u: goto label_1476f8;
            case 0x14775Cu: goto label_14775c;
            case 0x14778Cu: goto label_14778c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14779Cu;
    // 0x14779c: 0x0  nop
    ctx->pc = 0x14779cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
