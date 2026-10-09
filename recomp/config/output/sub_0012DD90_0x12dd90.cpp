#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DD90
// Address: 0x12dd90 - 0x12dee8
void sub_0012DD90_0x12dd90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DD90_0x12dd90");
#endif

    switch (ctx->pc) {
        case 0x12de38u: goto label_12de38;
        case 0x12dea0u: goto label_12dea0;
        case 0x12deb8u: goto label_12deb8;
        default: break;
    }

    ctx->pc = 0x12dd90u;

    // 0x12dd90: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12dd90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12dd94: 0x240b0020  addiu       $t3, $zero, 0x20
    ctx->pc = 0x12dd94u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x12dd98: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12dd98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12dd9c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x12dd9cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dda0: 0x3a420001  xori        $v0, $s2, 0x1
    ctx->pc = 0x12dda0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) ^ (uint64_t)(uint16_t)1);
    // 0x12dda4: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x12dda4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x12dda8: 0x162180b  movn        $v1, $t3, $v0
    ctx->pc = 0x12dda8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 11));
    // 0x12ddac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ddacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ddb0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12ddb0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ddb4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12ddb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ddb8: 0x223001a  div         $zero, $s1, $v1
    ctx->pc = 0x12ddb8u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x12ddbc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ddbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ddc0: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x12ddc0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ddc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ddc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ddc8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12ddc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12ddcc: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x12ddccu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ddd0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12ddd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12ddd4: 0x120a82d  daddu       $s5, $t1, $zero
    ctx->pc = 0x12ddd4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ddd8: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12ddd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12dddc: 0x140b02d  daddu       $s6, $t2, $zero
    ctx->pc = 0x12dddcu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dde0: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x12dde0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x12dde4: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x12dde4u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dde8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x12dde8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x12ddec: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12DDECu;
    {
        const bool branch_taken_0x12ddec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x12ddec) {
            ctx->pc = 0x12DDF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12DDECu;
            // 0x12ddf0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12DDF4u;
            goto label_12ddf4;
        }
    }
    ctx->pc = 0x12DDF4u;
label_12ddf4:
    // 0x12ddf4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x12ddf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ddf8: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x12ddf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12ddfc: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x12ddfcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12de00: 0x5810  mfhi        $t3
    ctx->pc = 0x12de00u;
    SET_GPR_U64(ctx, 11, ctx->hi);
    // 0x12de04: 0x6b5823  subu        $t3, $v1, $t3
    ctx->pc = 0x12de04u;
    SET_GPR_S32(ctx, 11, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x12de08: 0x163001a  div         $zero, $t3, $v1
    ctx->pc = 0x12de08u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 11);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x12de0c: 0x4010  mfhi        $t0
    ctx->pc = 0x12de0cu;
    SET_GPR_U64(ctx, 8, ctx->hi);
    // 0x12de10: 0x2281021  addu        $v0, $s1, $t0
    ctx->pc = 0x12de10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 8)));
    // 0x12de14: 0xae680000  sw          $t0, 0x0($s3)
    ctx->pc = 0x12de14u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 8));
    // 0x12de18: 0x2449001f  addiu       $t1, $v0, 0x1F
    ctx->pc = 0x12de18u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 31));
    // 0x12de1c: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x12de1cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x12de20: 0x123100b  movn        $v0, $t1, $v1
    ctx->pc = 0x12de20u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 9));
    // 0x12de24: 0x21143  sra         $v0, $v0, 5
    ctx->pc = 0x12de24u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 5));
    // 0x12de28: 0x521018  mult        $v0, $v0, $s2
    ctx->pc = 0x12de28u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 18); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x12de2c: 0x280c0  sll         $s0, $v0, 3
    ctx->pc = 0x12de2cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x12de30: 0xc049be0  jal         func_126F80
    ctx->pc = 0x12DE30u;
    SET_GPR_U32(ctx, 31, 0x12DE38u);
    ctx->pc = 0x12DE34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12DE30u;
            // 0x12de34: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126F80u;
    if (runtime->hasFunction(0x126F80u)) {
        auto targetFn = runtime->lookupFunction(0x126F80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DE38u; }
        if (ctx->pc != 0x12DE38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126F80_0x126f80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DE38u; }
        if (ctx->pc != 0x12DE38u) { return; }
    }
    ctx->pc = 0x12DE38u;
label_12de38:
    // 0x12de38: 0x108040  sll         $s0, $s0, 1
    ctx->pc = 0x12de38u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x12de3c: 0x24060800  addiu       $a2, $zero, 0x800
    ctx->pc = 0x12de3cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x12de40: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x12de40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x12de44: 0x26050004  addiu       $a1, $s0, 0x4
    ctx->pc = 0x12de44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x12de48: 0x26100803  addiu       $s0, $s0, 0x803
    ctx->pc = 0x12de48u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2051));
    // 0x12de4c: 0x28a40000  slti        $a0, $a1, 0x0
    ctx->pc = 0x12de4cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x12de50: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x12de50u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12de54: 0x204180b  movn        $v1, $s0, $a0
    ctx->pc = 0x12de54u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 16));
    // 0x12de58: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x12de58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12de5c: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x12de5cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x12de60: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x12de60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x12de64: 0xa32823  subu        $a1, $a1, $v1
    ctx->pc = 0x12de64u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x12de68: 0xc53023  subu        $a2, $a2, $a1
    ctx->pc = 0x12de68u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x12de6c: 0x24c707ff  addiu       $a3, $a2, 0x7FF
    ctx->pc = 0x12de6cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 2047));
    // 0x12de70: 0x28c50000  slti        $a1, $a2, 0x0
    ctx->pc = 0x12de70u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x12de74: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x12de74u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12de78: 0xe5180b  movn        $v1, $a3, $a1
    ctx->pc = 0x12de78u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 7));
    // 0x12de7c: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x12de7cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x12de80: 0x32ac0  sll         $a1, $v1, 11
    ctx->pc = 0x12de80u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x12de84: 0xc51823  subu        $v1, $a2, $a1
    ctx->pc = 0x12de84u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x12de88: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x12de88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12de8c: 0xae820000  sw          $v0, 0x0($s4)
    ctx->pc = 0x12de8cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
    // 0x12de90: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12de90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12de94: 0x8e660000  lw          $a2, 0x0($s3)
    ctx->pc = 0x12de94u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12de98: 0xc04b758  jal         func_12DD60
    ctx->pc = 0x12DE98u;
    SET_GPR_U32(ctx, 31, 0x12DEA0u);
    ctx->pc = 0x12DE9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12DE98u;
            // 0x12de9c: 0x2263021  addu        $a2, $s1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DD60u;
    if (runtime->hasFunction(0x12DD60u)) {
        auto targetFn = runtime->lookupFunction(0x12DD60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DEA0u; }
        if (ctx->pc != 0x12DEA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DD60_0x12dd60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DEA0u; }
        if (ctx->pc != 0x12DEA0u) { return; }
    }
    ctx->pc = 0x12DEA0u;
label_12dea0:
    // 0x12dea0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x12dea0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dea4: 0xaea20000  sw          $v0, 0x0($s5)
    ctx->pc = 0x12dea4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
    // 0x12dea8: 0x8e660000  lw          $a2, 0x0($s3)
    ctx->pc = 0x12dea8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12deac: 0x8e850000  lw          $a1, 0x0($s4)
    ctx->pc = 0x12deacu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12deb0: 0xc04b758  jal         func_12DD60
    ctx->pc = 0x12DEB0u;
    SET_GPR_U32(ctx, 31, 0x12DEB8u);
    ctx->pc = 0x12DEB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12DEB0u;
            // 0x12deb4: 0x2e63021  addu        $a2, $s7, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DD60u;
    if (runtime->hasFunction(0x12DD60u)) {
        auto targetFn = runtime->lookupFunction(0x12DD60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DEB8u; }
        if (ctx->pc != 0x12DEB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DD60_0x12dd60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DEB8u; }
        if (ctx->pc != 0x12DEB8u) { return; }
    }
    ctx->pc = 0x12DEB8u;
label_12deb8:
    // 0x12deb8: 0xaec20000  sw          $v0, 0x0($s6)
    ctx->pc = 0x12deb8u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 2));
    // 0x12debc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12debcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12dec0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12dec0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12dec4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12dec4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12dec8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12dec8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12decc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12deccu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ded0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12ded0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ded4: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12ded4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12ded8: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x12ded8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12dedc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x12dedcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12dee0: 0x3e00008  jr          $ra
    ctx->pc = 0x12DEE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DEE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DEE0u;
            // 0x12dee4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DDF4u: goto label_12ddf4;
            case 0x12DE38u: goto label_12de38;
            case 0x12DEA0u: goto label_12dea0;
            case 0x12DEB8u: goto label_12deb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DEE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
