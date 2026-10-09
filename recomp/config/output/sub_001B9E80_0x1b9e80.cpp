#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9E80
// Address: 0x1b9e80 - 0x1ba038
void sub_001B9E80_0x1b9e80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9E80_0x1b9e80");
#endif

    switch (ctx->pc) {
        case 0x1b9ef4u: goto label_1b9ef4;
        case 0x1b9f10u: goto label_1b9f10;
        case 0x1b9f3cu: goto label_1b9f3c;
        case 0x1b9f70u: goto label_1b9f70;
        case 0x1b9fc4u: goto label_1b9fc4;
        case 0x1b9fe8u: goto label_1b9fe8;
        case 0x1ba010u: goto label_1ba010;
        case 0x1ba024u: goto label_1ba024;
        default: break;
    }

    ctx->pc = 0x1b9e80u;

    // 0x1b9e80: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b9e80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b9e84: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1b9e84u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1b9e88: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b9e88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b9e8c: 0x24a54c10  addiu       $a1, $a1, 0x4C10
    ctx->pc = 0x1b9e8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19472));
    // 0x1b9e90: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b9e90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9e94: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9e94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9e98: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b9e98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b9e9c: 0x84860038  lh          $a2, 0x38($a0)
    ctx->pc = 0x1b9e9cu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 56)));
    // 0x1b9ea0: 0x80830004  lb          $v1, 0x4($a0)
    ctx->pc = 0x1b9ea0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1b9ea4: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1b9ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1b9ea8: 0x80b00000  lb          $s0, 0x0($a1)
    ctx->pc = 0x1b9ea8u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1b9eac: 0x10680018  beq         $v1, $t0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B9EACu;
    {
        const bool branch_taken_0x1b9eac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        ctx->pc = 0x1B9EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9EACu;
            // 0x1b9eb0: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9eac) {
            ctx->pc = 0x1B9F10u;
            goto label_1b9f10;
        }
    }
    ctx->pc = 0x1B9EB4u;
    // 0x1b9eb4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9EB4u;
    {
        const bool branch_taken_0x1b9eb4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9eb4) {
            ctx->pc = 0x1B9EC4u;
            goto label_1b9ec4;
        }
    }
    ctx->pc = 0x1B9EBCu;
    // 0x1b9ebc: 0x1000005a  b           . + 4 + (0x5A << 2)
    ctx->pc = 0x1B9EBCu;
    {
        const bool branch_taken_0x1b9ebc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9EBCu;
            // 0x1b9ec0: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9ebc) {
            ctx->pc = 0x1BA028u;
            goto label_1ba028;
        }
    }
    ctx->pc = 0x1B9EC4u;
label_1b9ec4:
    // 0x1b9ec4: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1b9ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b9ec8: 0xa2220004  sb          $v0, 0x4($s1)
    ctx->pc = 0x1b9ec8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b9ecc: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x1b9eccu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1b9ed0: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1B9ED0u;
    {
        const bool branch_taken_0x1b9ed0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9ed0) {
            ctx->pc = 0x1B9F08u;
            goto label_1b9f08;
        }
    }
    ctx->pc = 0x1B9ED8u;
    // 0x1b9ed8: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9ed8u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9edc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9edcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9ee0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9ee0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9ee4: 0x2627002c  addiu       $a3, $s1, 0x2C
    ctx->pc = 0x1b9ee4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9ee8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9ee8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9eec: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9EECu;
    SET_GPR_U32(ctx, 31, 0x1B9EF4u);
    ctx->pc = 0x1B9EF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9EECu;
            // 0x1b9ef0: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9EF4u; }
        if (ctx->pc != 0x1B9EF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9EF4u; }
        if (ctx->pc != 0x1B9EF4u) { return; }
    }
    ctx->pc = 0x1B9EF4u;
label_1b9ef4:
    // 0x1b9ef4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1b9ef4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b9ef8: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1b9ef8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1b9efc: 0xa6240008  sh          $a0, 0x8($s1)
    ctx->pc = 0x1b9efcu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 4));
    // 0x1b9f00: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9F00u;
    {
        const bool branch_taken_0x1b9f00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9F00u;
            // 0x1b9f04: 0xa623000a  sh          $v1, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9f00) {
            ctx->pc = 0x1B9F10u;
            goto label_1b9f10;
        }
    }
    ctx->pc = 0x1B9F08u;
label_1b9f08:
    // 0x1b9f08: 0xc06e650  jal         func_1B9940
    ctx->pc = 0x1B9F08u;
    SET_GPR_U32(ctx, 31, 0x1B9F10u);
    ctx->pc = 0x1B9940u;
    if (runtime->hasFunction(0x1B9940u)) {
        auto targetFn = runtime->lookupFunction(0x1B9940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F10u; }
        if (ctx->pc != 0x1B9F10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B9940_0x1b9940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F10u; }
        if (ctx->pc != 0x1B9F10u) { return; }
    }
    ctx->pc = 0x1B9F10u;
label_1b9f10:
    // 0x1b9f10: 0x8623000a  lh          $v1, 0xA($s1)
    ctx->pc = 0x1b9f10u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x1b9f14: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b9f14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b9f18: 0xa623000a  sh          $v1, 0xA($s1)
    ctx->pc = 0x1b9f18u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9f1c: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b9f1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b9f20: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b9f20u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b9f24: 0x4610012  bgez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B9F24u;
    {
        const bool branch_taken_0x1b9f24 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x1b9f24) {
            ctx->pc = 0x1B9F70u;
            goto label_1b9f70;
        }
    }
    ctx->pc = 0x1B9F2Cu;
    // 0x1b9f2c: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1b9f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1b9f30: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b9f30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9f34: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B9F34u;
    SET_GPR_U32(ctx, 31, 0x1B9F3Cu);
    ctx->pc = 0x1B9F38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9F34u;
            // 0x1b9f38: 0xa622000a  sh          $v0, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F3Cu; }
        if (ctx->pc != 0x1B9F3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F3Cu; }
        if (ctx->pc != 0x1B9F3Cu) { return; }
    }
    ctx->pc = 0x1B9F3Cu;
label_1b9f3c:
    // 0x1b9f3c: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b9f3cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b9f40: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9f40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9f44: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1b9f44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b9f48: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9f48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9f4c: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1b9f4cu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1b9f50: 0x2627002c  addiu       $a3, $s1, 0x2C
    ctx->pc = 0x1b9f50u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9f54: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b9f54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b9f58: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b9f58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9f5c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b9f5cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9f60: 0x82220002  lb          $v0, 0x2($s1)
    ctx->pc = 0x1b9f60u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9f64: 0x1810  mfhi        $v1
    ctx->pc = 0x1b9f64u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1b9f68: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B9F68u;
    SET_GPR_U32(ctx, 31, 0x1B9F70u);
    ctx->pc = 0x1B9F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9F68u;
            // 0x1b9f6c: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F70u; }
        if (ctx->pc != 0x1B9F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9F70u; }
        if (ctx->pc != 0x1B9F70u) { return; }
    }
    ctx->pc = 0x1B9F70u;
label_1b9f70:
    // 0x1b9f70: 0x86230008  lh          $v1, 0x8($s1)
    ctx->pc = 0x1b9f70u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1b9f74: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b9f74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b9f78: 0xa6230008  sh          $v1, 0x8($s1)
    ctx->pc = 0x1b9f78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9f7c: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x1b9f7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1b9f80: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b9f80u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b9f84: 0x4610027  bgez        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1B9F84u;
    {
        const bool branch_taken_0x1b9f84 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x1b9f84) {
            ctx->pc = 0x1BA024u;
            goto label_1ba024;
        }
    }
    ctx->pc = 0x1B9F8Cu;
    // 0x1b9f8c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1b9f8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b9f90: 0xa6220008  sh          $v0, 0x8($s1)
    ctx->pc = 0x1b9f90u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b9f94: 0x82220001  lb          $v0, 0x1($s1)
    ctx->pc = 0x1b9f94u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1b9f98: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B9F98u;
    {
        const bool branch_taken_0x1b9f98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9F98u;
            // 0x1b9f9c: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9f98) {
            ctx->pc = 0x1B9FF0u;
            goto label_1b9ff0;
        }
    }
    ctx->pc = 0x1B9FA0u;
    // 0x1b9fa0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b9fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b9fa4: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b9fa4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b9fa8: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b9fac: 0x2624002c  addiu       $a0, $s1, 0x2C
    ctx->pc = 0x1b9facu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9fb0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b9fb4: 0x27a6003c  addiu       $a2, $sp, 0x3C
    ctx->pc = 0x1b9fb4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x1b9fb8: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1b9fb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9fbc: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1B9FBCu;
    SET_GPR_U32(ctx, 31, 0x1B9FC4u);
    ctx->pc = 0x1B9FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9FBCu;
            // 0x1b9fc0: 0x27a70038  addiu       $a3, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9FC4u; }
        if (ctx->pc != 0x1B9FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9FC4u; }
        if (ctx->pc != 0x1B9FC4u) { return; }
    }
    ctx->pc = 0x1B9FC4u;
label_1b9fc4:
    // 0x1b9fc4: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1B9FC4u;
    {
        const bool branch_taken_0x1b9fc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9fc4) {
            ctx->pc = 0x1BA024u;
            goto label_1ba024;
        }
    }
    ctx->pc = 0x1B9FCCu;
    // 0x1b9fcc: 0x82250002  lb          $a1, 0x2($s1)
    ctx->pc = 0x1b9fccu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b9fd0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1b9fd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b9fd4: 0x8fa7003c  lw          $a3, 0x3C($sp)
    ctx->pc = 0x1b9fd4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1b9fd8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b9fd8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9fdc: 0x8fa80038  lw          $t0, 0x38($sp)
    ctx->pc = 0x1b9fdcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1b9fe0: 0xc06b2d8  jal         func_1ACB60
    ctx->pc = 0x1B9FE0u;
    SET_GPR_U32(ctx, 31, 0x1B9FE8u);
    ctx->pc = 0x1B9FE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9FE0u;
            // 0x1b9fe4: 0x24092000  addiu       $t1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACB60u;
    if (runtime->hasFunction(0x1ACB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9FE8u; }
        if (ctx->pc != 0x1B9FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACB60_0x1acb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9FE8u; }
        if (ctx->pc != 0x1B9FE8u) { return; }
    }
    ctx->pc = 0x1B9FE8u;
label_1b9fe8:
    // 0x1b9fe8: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1B9FE8u;
    {
        const bool branch_taken_0x1b9fe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9fe8) {
            ctx->pc = 0x1BA024u;
            goto label_1ba024;
        }
    }
    ctx->pc = 0x1B9FF0u;
label_1b9ff0:
    // 0x1b9ff0: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b9ff0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b9ff4: 0x24424bf0  addiu       $v0, $v0, 0x4BF0
    ctx->pc = 0x1b9ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19440));
    // 0x1b9ff8: 0x2624002c  addiu       $a0, $s1, 0x2C
    ctx->pc = 0x1b9ff8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 44));
    // 0x1b9ffc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b9ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ba000: 0x27a6003c  addiu       $a2, $sp, 0x3C
    ctx->pc = 0x1ba000u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x1ba004: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1ba004u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ba008: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1BA008u;
    SET_GPR_U32(ctx, 31, 0x1BA010u);
    ctx->pc = 0x1BA00Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA008u;
            // 0x1ba00c: 0x27a70038  addiu       $a3, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA010u; }
        if (ctx->pc != 0x1BA010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA010u; }
        if (ctx->pc != 0x1BA010u) { return; }
    }
    ctx->pc = 0x1BA010u;
label_1ba010:
    // 0x1ba010: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BA010u;
    {
        const bool branch_taken_0x1ba010 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba010) {
            ctx->pc = 0x1BA024u;
            goto label_1ba024;
        }
    }
    ctx->pc = 0x1BA018u;
    // 0x1ba018: 0x8fa5003c  lw          $a1, 0x3C($sp)
    ctx->pc = 0x1ba018u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1ba01c: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1BA01Cu;
    SET_GPR_U32(ctx, 31, 0x1BA024u);
    ctx->pc = 0x1BA020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA01Cu;
            // 0x1ba020: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA024u; }
        if (ctx->pc != 0x1BA024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA024u; }
        if (ctx->pc != 0x1BA024u) { return; }
    }
    ctx->pc = 0x1BA024u;
label_1ba024:
    // 0x1ba024: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ba024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1ba028:
    // 0x1ba028: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ba028u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ba02c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba02cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba030: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA030u;
            // 0x1ba034: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B9EC4u: goto label_1b9ec4;
            case 0x1B9EF4u: goto label_1b9ef4;
            case 0x1B9F08u: goto label_1b9f08;
            case 0x1B9F10u: goto label_1b9f10;
            case 0x1B9F3Cu: goto label_1b9f3c;
            case 0x1B9F70u: goto label_1b9f70;
            case 0x1B9FC4u: goto label_1b9fc4;
            case 0x1B9FE8u: goto label_1b9fe8;
            case 0x1B9FF0u: goto label_1b9ff0;
            case 0x1BA010u: goto label_1ba010;
            case 0x1BA024u: goto label_1ba024;
            case 0x1BA028u: goto label_1ba028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA038u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
