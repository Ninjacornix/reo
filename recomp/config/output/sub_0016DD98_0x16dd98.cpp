#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016DD98
// Address: 0x16dd98 - 0x16df80
void sub_0016DD98_0x16dd98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016DD98_0x16dd98");
#endif

    switch (ctx->pc) {
        case 0x16ddecu: goto label_16ddec;
        default: break;
    }

    ctx->pc = 0x16dd98u;

    // 0x16dd98: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16dd98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16dd9c: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x16dd9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x16dda0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16dda0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16dda4: 0x3c130024  lui         $s3, 0x24
    ctx->pc = 0x16dda4u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)36 << 16));
    // 0x16dda8: 0x2629821  addu        $s3, $s3, $v0
    ctx->pc = 0x16dda8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x16ddac: 0x8e730af0  lw          $s3, 0xAF0($s3)
    ctx->pc = 0x16ddacu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 2800)));
    // 0x16ddb0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16ddb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16ddb4: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16ddb4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ddb8: 0x3c060157  lui         $a2, 0x157
    ctx->pc = 0x16ddb8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)343 << 16));
    // 0x16ddbc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x16ddbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ddc0: 0x34c652a0  ori         $a2, $a2, 0x52A0
    ctx->pc = 0x16ddc0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)21152);
    // 0x16ddc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16ddc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16ddc8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16ddc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16ddcc: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x16ddccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ddd0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16ddd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16ddd4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16ddd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16ddd8: 0x3c120024  lui         $s2, 0x24
    ctx->pc = 0x16ddd8u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)36 << 16));
    // 0x16dddc: 0x2429021  addu        $s2, $s2, $v0
    ctx->pc = 0x16dddcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x16dde0: 0x8e520898  lw          $s2, 0x898($s2)
    ctx->pc = 0x16dde0u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2200)));
    // 0x16dde4: 0xc056ebc  jal         func_15BAF0
    ctx->pc = 0x16DDE4u;
    SET_GPR_U32(ctx, 31, 0x16DDECu);
    ctx->pc = 0x16DDE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DDE4u;
            // 0x16dde8: 0x100a02d  daddu       $s4, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BAF0u;
    if (runtime->hasFunction(0x15BAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15BAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DDECu; }
        if (ctx->pc != 0x16DDECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BAF0_0x15baf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16DDECu; }
        if (ctx->pc != 0x16DDECu) { return; }
    }
    ctx->pc = 0x16DDECu;
label_16ddec:
    // 0x16ddec: 0x501823  subu        $v1, $v0, $s0
    ctx->pc = 0x16ddecu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x16ddf0: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x16ddf0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16ddf4: 0x12200044  beqz        $s1, . + 4 + (0x44 << 2)
    ctx->pc = 0x16DDF4u;
    {
        const bool branch_taken_0x16ddf4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DDF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DDF4u;
            // 0x16ddf8: 0x2180b  movn        $v1, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ddf4) {
            ctx->pc = 0x16DF08u;
            goto label_16df08;
        }
    }
    ctx->pc = 0x16DDFCu;
    // 0x16ddfc: 0x24027512  addiu       $v0, $zero, 0x7512
    ctx->pc = 0x16ddfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29970));
    // 0x16de00: 0x12620005  beq         $s3, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16DE00u;
    {
        const bool branch_taken_0x16de00 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 2));
        ctx->pc = 0x16DE04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE00u;
            // 0x16de04: 0x3402ea24  ori         $v0, $zero, 0xEA24 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)59940);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16de00) {
            ctx->pc = 0x16DE18u;
            goto label_16de18;
        }
    }
    ctx->pc = 0x16DE08u;
    // 0x16de08: 0x56620040  bnel        $s3, $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x16DE08u;
    {
        const bool branch_taken_0x16de08 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        if (branch_taken_0x16de08) {
            ctx->pc = 0x16DE0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE08u;
            // 0x16de0c: 0x72001a  div         $zero, $v1, $s2 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 18);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DF0Cu;
            goto label_16df0c;
        }
    }
    ctx->pc = 0x16DE10u;
    // 0x16de10: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16DE10u;
    {
        const bool branch_taken_0x16de10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DE14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE10u;
            // 0x16de14: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16de10) {
            ctx->pc = 0x16DE28u;
            goto label_16de28;
        }
    }
    ctx->pc = 0x16DE18u;
label_16de18:
    // 0x16de18: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x16de18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x16de1c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16DE1Cu;
    {
        const bool branch_taken_0x16de1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE1Cu;
            // 0x16de20: 0x244808c0  addiu       $t0, $v0, 0x8C0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 2240));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16de1c) {
            ctx->pc = 0x16DE2Cu;
            goto label_16de2c;
        }
    }
    ctx->pc = 0x16DE24u;
    // 0x16de24: 0x0  nop
    ctx->pc = 0x16de24u;
    // NOP
label_16de28:
    // 0x16de28: 0x244808e0  addiu       $t0, $v0, 0x8E0
    ctx->pc = 0x16de28u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 2272));
label_16de2c:
    // 0x16de2c: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x16de2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x16de30: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x16de30u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16de34: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x16DE34u;
    {
        const bool branch_taken_0x16de34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16de34) {
            ctx->pc = 0x16DE38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE34u;
            // 0x16de38: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DE3Cu;
            goto label_16de3c;
        }
    }
    ctx->pc = 0x16DE3Cu;
label_16de3c:
    // 0x16de3c: 0x8d030004  lw          $v1, 0x4($t0)
    ctx->pc = 0x16de3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x16de40: 0x8d060008  lw          $a2, 0x8($t0)
    ctx->pc = 0x16de40u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x16de44: 0x2010  mfhi        $a0
    ctx->pc = 0x16de44u;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x16de48: 0x2812  mflo        $a1
    ctx->pc = 0x16de48u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x16de4c: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x16de4cu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16de50: 0xa0482d  daddu       $t1, $a1, $zero
    ctx->pc = 0x16de50u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16de54: 0x1010  mfhi        $v0
    ctx->pc = 0x16de54u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x16de58: 0x2012  mflo        $a0
    ctx->pc = 0x16de58u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x16de5c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16de5cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16de60: 0x66102a  slt         $v0, $v1, $a2
    ctx->pc = 0x16de60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x16de64: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16DE64u;
    {
        const bool branch_taken_0x16de64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DE68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE64u;
            // 0x16de68: 0x80502d  daddu       $t2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16de64) {
            ctx->pc = 0x16DE90u;
            goto label_16de90;
        }
    }
    ctx->pc = 0x16DE6Cu;
    // 0x16de6c: 0x8d020014  lw          $v0, 0x14($t0)
    ctx->pc = 0x16de6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 20)));
    // 0x16de70: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16de70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16de74: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x16de74u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16de78: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x16DE78u;
    {
        const bool branch_taken_0x16de78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16de78) {
            ctx->pc = 0x16DE7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE78u;
            // 0x16de7c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DE80u;
            goto label_16de80;
        }
    }
    ctx->pc = 0x16DE80u;
label_16de80:
    // 0x16de80: 0x1812  mflo        $v1
    ctx->pc = 0x16de80u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x16de84: 0x2010  mfhi        $a0
    ctx->pc = 0x16de84u;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x16de88: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x16DE88u;
    {
        const bool branch_taken_0x16de88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DE8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE88u;
            // 0x16de8c: 0x60302d  daddu       $a2, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16de88) {
            ctx->pc = 0x16DEF0u;
            goto label_16def0;
        }
    }
    ctx->pc = 0x16DE90u;
label_16de90:
    // 0x16de90: 0x8d02000c  lw          $v0, 0xC($t0)
    ctx->pc = 0x16de90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
    // 0x16de94: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x16de94u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x16de98: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x16de98u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16de9c: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x16DE9Cu;
    {
        const bool branch_taken_0x16de9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16de9c) {
            ctx->pc = 0x16DEA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DE9Cu;
            // 0x16dea0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DEA4u;
            goto label_16dea4;
        }
    }
    ctx->pc = 0x16DEA4u;
label_16dea4:
    // 0x16dea4: 0x8d060010  lw          $a2, 0x10($t0)
    ctx->pc = 0x16dea4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 16)));
    // 0x16dea8: 0x1810  mfhi        $v1
    ctx->pc = 0x16dea8u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x16deac: 0x2012  mflo        $a0
    ctx->pc = 0x16deacu;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x16deb0: 0x66102a  slt         $v0, $v1, $a2
    ctx->pc = 0x16deb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x16deb4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16DEB4u;
    {
        const bool branch_taken_0x16deb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DEB4u;
            // 0x16deb8: 0x24850001  addiu       $a1, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16deb4) {
            ctx->pc = 0x16DED0u;
            goto label_16ded0;
        }
    }
    ctx->pc = 0x16DEBCu;
    // 0x16debc: 0x8d02001c  lw          $v0, 0x1C($t0)
    ctx->pc = 0x16debcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 28)));
    // 0x16dec0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x16dec0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16dec4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x16DEC4u;
    {
        const bool branch_taken_0x16dec4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DEC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DEC4u;
            // 0x16dec8: 0x623821  addu        $a3, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dec4) {
            ctx->pc = 0x16DEF4u;
            goto label_16def4;
        }
    }
    ctx->pc = 0x16DECCu;
    // 0x16decc: 0x0  nop
    ctx->pc = 0x16deccu;
    // NOP
label_16ded0:
    // 0x16ded0: 0x8d020014  lw          $v0, 0x14($t0)
    ctx->pc = 0x16ded0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 20)));
    // 0x16ded4: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x16ded4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x16ded8: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x16ded8u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16dedc: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x16DEDCu;
    {
        const bool branch_taken_0x16dedc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16dedc) {
            ctx->pc = 0x16DEE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DEDCu;
            // 0x16dee0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DEE4u;
            goto label_16dee4;
        }
    }
    ctx->pc = 0x16DEE4u;
label_16dee4:
    // 0x16dee4: 0x1812  mflo        $v1
    ctx->pc = 0x16dee4u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x16dee8: 0x2010  mfhi        $a0
    ctx->pc = 0x16dee8u;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x16deec: 0x24660001  addiu       $a2, $v1, 0x1
    ctx->pc = 0x16deecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_16def0:
    // 0x16def0: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x16def0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_16def4:
    // 0x16def4: 0x8d020018  lw          $v0, 0x18($t0)
    ctx->pc = 0x16def4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 24)));
    // 0x16def8: 0x4a1818  mult        $v1, $v0, $t2
    ctx->pc = 0x16def8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x16defc: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x16DEFCu;
    {
        const bool branch_taken_0x16defc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DEFCu;
            // 0x16df00: 0x652821  addu        $a1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16defc) {
            ctx->pc = 0x16DF4Cu;
            goto label_16df4c;
        }
    }
    ctx->pc = 0x16DF04u;
    // 0x16df04: 0x0  nop
    ctx->pc = 0x16df04u;
    // NOP
label_16df08:
    // 0x16df08: 0x72001a  div         $zero, $v1, $s2
    ctx->pc = 0x16df08u;
    { int32_t divisor = GPR_S32(ctx, 18);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
label_16df0c:
    // 0x16df0c: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x16df0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x16df10: 0x2404003c  addiu       $a0, $zero, 0x3C
    ctx->pc = 0x16df10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x16df14: 0x52400001  beql        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x16DF14u;
    {
        const bool branch_taken_0x16df14 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x16df14) {
            ctx->pc = 0x16DF18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DF14u;
            // 0x16df18: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DF1Cu;
            goto label_16df1c;
        }
    }
    ctx->pc = 0x16DF1Cu;
label_16df1c:
    // 0x16df1c: 0x2405003c  addiu       $a1, $zero, 0x3C
    ctx->pc = 0x16df1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x16df20: 0x2406003c  addiu       $a2, $zero, 0x3C
    ctx->pc = 0x16df20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x16df24: 0x1012  mflo        $v0
    ctx->pc = 0x16df24u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x16df28: 0x3810  mfhi        $a3
    ctx->pc = 0x16df28u;
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x16df2c: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x16df2cu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16df30: 0x1012  mflo        $v0
    ctx->pc = 0x16df30u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x16df34: 0x2010  mfhi        $a0
    ctx->pc = 0x16df34u;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x16df38: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x16df38u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16df3c: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x16df3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16df40: 0x1012  mflo        $v0
    ctx->pc = 0x16df40u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x16df44: 0x2810  mfhi        $a1
    ctx->pc = 0x16df44u;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x16df48: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x16df48u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_16df4c:
    // 0x16df4c: 0xae870014  sw          $a3, 0x14($s4)
    ctx->pc = 0x16df4cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 20), GPR_U32(ctx, 7));
    // 0x16df50: 0xae890008  sw          $t1, 0x8($s4)
    ctx->pc = 0x16df50u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 9));
    // 0x16df54: 0xae85000c  sw          $a1, 0xC($s4)
    ctx->pc = 0x16df54u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 12), GPR_U32(ctx, 5));
    // 0x16df58: 0xae860010  sw          $a2, 0x10($s4)
    ctx->pc = 0x16df58u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 16), GPR_U32(ctx, 6));
    // 0x16df5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16df5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16df60: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16df60u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16df64: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16df64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16df68: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16df68u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16df6c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16df6cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16df70: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16df70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16df74: 0x3e00008  jr          $ra
    ctx->pc = 0x16DF74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16DF78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DF74u;
            // 0x16df78: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16DDECu: goto label_16ddec;
            case 0x16DE18u: goto label_16de18;
            case 0x16DE28u: goto label_16de28;
            case 0x16DE2Cu: goto label_16de2c;
            case 0x16DE3Cu: goto label_16de3c;
            case 0x16DE80u: goto label_16de80;
            case 0x16DE90u: goto label_16de90;
            case 0x16DEA4u: goto label_16dea4;
            case 0x16DED0u: goto label_16ded0;
            case 0x16DEE4u: goto label_16dee4;
            case 0x16DEF0u: goto label_16def0;
            case 0x16DEF4u: goto label_16def4;
            case 0x16DF08u: goto label_16df08;
            case 0x16DF0Cu: goto label_16df0c;
            case 0x16DF1Cu: goto label_16df1c;
            case 0x16DF4Cu: goto label_16df4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16DF7Cu;
    // 0x16df7c: 0x0  nop
    ctx->pc = 0x16df7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
