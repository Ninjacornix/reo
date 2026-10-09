#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112C58
// Address: 0x112c58 - 0x112d20
void sub_00112C58_0x112c58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112C58_0x112c58");
#endif

    switch (ctx->pc) {
        case 0x112c88u: goto label_112c88;
        default: break;
    }

    ctx->pc = 0x112c58u;

    // 0x112c58: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x112c58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x112c5c: 0x63400  sll         $a2, $a2, 16
    ctx->pc = 0x112c5cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 16));
    // 0x112c60: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x112c60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x112c64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x112c64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x112c68: 0x48c00  sll         $s1, $a0, 16
    ctx->pc = 0x112c68u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x112c6c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x112c6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x112c70: 0x58400  sll         $s0, $a1, 16
    ctx->pc = 0x112c70u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x112c74: 0x108403  sra         $s0, $s0, 16
    ctx->pc = 0x112c74u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 16));
    // 0x112c78: 0x118c03  sra         $s1, $s1, 16
    ctx->pc = 0x112c78u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 16));
    // 0x112c7c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x112c7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x112c80: 0xc0449be  jal         func_1126F8
    ctx->pc = 0x112C80u;
    SET_GPR_U32(ctx, 31, 0x112C88u);
    ctx->pc = 0x112C84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112C80u;
            // 0x112c84: 0x69403  sra         $s2, $a2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 6), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1126F8u;
    if (runtime->hasFunction(0x1126F8u)) {
        auto targetFn = runtime->lookupFunction(0x1126F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112C88u; }
        if (ctx->pc != 0x112C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112C88u; }
        if (ctx->pc != 0x112C88u) { return; }
    }
    ctx->pc = 0x112C88u;
label_112c88:
    // 0x112c88: 0x2603003f  addiu       $v1, $s0, 0x3F
    ctx->pc = 0x112c88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 63));
    // 0x112c8c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x112c8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112c90: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x112c90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x112c94: 0x2610007e  addiu       $s0, $s0, 0x7E
    ctx->pc = 0x112c94u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 126));
    // 0x112c98: 0x83102a  slt         $v0, $a0, $v1
    ctx->pc = 0x112c98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x112c9c: 0x32310002  andi        $s1, $s1, 0x2
    ctx->pc = 0x112c9cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)2);
    // 0x112ca0: 0x62800b  movn        $s0, $v1, $v0
    ctx->pc = 0x112ca0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 3));
    // 0x112ca4: 0x12200007  beqz        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x112CA4u;
    {
        const bool branch_taken_0x112ca4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x112CA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112CA4u;
            // 0x112ca8: 0x108183  sra         $s0, $s0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112ca4) {
            ctx->pc = 0x112CC4u;
            goto label_112cc4;
        }
    }
    ctx->pc = 0x112CACu;
    // 0x112cac: 0x2642003f  addiu       $v0, $s2, 0x3F
    ctx->pc = 0x112cacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 63));
    // 0x112cb0: 0x2643007e  addiu       $v1, $s2, 0x7E
    ctx->pc = 0x112cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 126));
    // 0x112cb4: 0x82202a  slt         $a0, $a0, $v0
    ctx->pc = 0x112cb4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x112cb8: 0x44180b  movn        $v1, $v0, $a0
    ctx->pc = 0x112cb8u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 2));
    // 0x112cbc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x112CBCu;
    {
        const bool branch_taken_0x112cbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112CBCu;
            // 0x112cc0: 0x33183  sra         $a2, $v1, 6 (Delay Slot)
        SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 3), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112cbc) {
            ctx->pc = 0x112CD8u;
            goto label_112cd8;
        }
    }
    ctx->pc = 0x112CC4u;
label_112cc4:
    // 0x112cc4: 0x2642001f  addiu       $v0, $s2, 0x1F
    ctx->pc = 0x112cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 31));
    // 0x112cc8: 0x2643003e  addiu       $v1, $s2, 0x3E
    ctx->pc = 0x112cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 62));
    // 0x112ccc: 0x82202a  slt         $a0, $a0, $v0
    ctx->pc = 0x112cccu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x112cd0: 0x44180b  movn        $v1, $v0, $a0
    ctx->pc = 0x112cd0u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 2));
    // 0x112cd4: 0x33143  sra         $a2, $v1, 5
    ctx->pc = 0x112cd4u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 3), 5));
label_112cd8:
    // 0x112cd8: 0xdca20000  ld          $v0, 0x0($a1)
    ctx->pc = 0x112cd8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x112cdc: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x112cdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x112ce0: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x112ce0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x112ce4: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x112ce4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x112ce8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x112ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x112cec: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x112cecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x112cf0: 0x14440003  bne         $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x112CF0u;
    {
        const bool branch_taken_0x112cf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x112CF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112CF0u;
            // 0x112cf4: 0x2061018  mult        $v0, $s0, $a2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x112cf0) {
            ctx->pc = 0x112D00u;
            goto label_112d00;
        }
    }
    ctx->pc = 0x112CF8u;
    // 0x112cf8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x112CF8u;
    {
        const bool branch_taken_0x112cf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x112CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112CF8u;
            // 0x112cfc: 0x21400  sll         $v0, $v0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112cf8) {
            ctx->pc = 0x112D04u;
            goto label_112d04;
        }
    }
    ctx->pc = 0x112D00u;
label_112d00:
    // 0x112d00: 0x21440  sll         $v0, $v0, 17
    ctx->pc = 0x112d00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 17));
label_112d04:
    // 0x112d04: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x112d04u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x112d08: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x112d08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x112d0c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x112d0cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x112d10: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x112d10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112d14: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x112d14u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112d18: 0x3e00008  jr          $ra
    ctx->pc = 0x112D18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112D18u;
            // 0x112d1c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112C88u: goto label_112c88;
            case 0x112CC4u: goto label_112cc4;
            case 0x112CD8u: goto label_112cd8;
            case 0x112D00u: goto label_112d00;
            case 0x112D04u: goto label_112d04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112D20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
