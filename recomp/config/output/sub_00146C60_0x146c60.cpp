#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146C60
// Address: 0x146c60 - 0x146dd8
void sub_00146C60_0x146c60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146C60_0x146c60");
#endif

    switch (ctx->pc) {
        case 0x146cf8u: goto label_146cf8;
        default: break;
    }

    ctx->pc = 0x146c60u;

    // 0x146c60: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x146c60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x146c64: 0xffbe0080  sd          $fp, 0x80($sp)
    ctx->pc = 0x146c64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 30));
    // 0x146c68: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x146c68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x146c6c: 0x100f02d  daddu       $fp, $t0, $zero
    ctx->pc = 0x146c6cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146c70: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x146c70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x146c74: 0xe0b82d  daddu       $s7, $a3, $zero
    ctx->pc = 0x146c74u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146c78: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x146c78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x146c7c: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x146c7cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146c80: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x146c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x146c84: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x146c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x146c88: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x146c88u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146c8c: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x146c8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x146c90: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x146c90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x146c94: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x146c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x146c98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x146c9c: 0x8e42008c  lw          $v0, 0x8C($s2)
    ctx->pc = 0x146c9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 140)));
    // 0x146ca0: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x146CA0u;
    {
        const bool branch_taken_0x146ca0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146CA0u;
            // 0x146ca4: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146ca0) {
            ctx->pc = 0x146D24u;
            goto label_146d24;
        }
    }
    ctx->pc = 0x146CA8u;
    // 0x146ca8: 0xde620018  ld          $v0, 0x18($s3)
    ctx->pc = 0x146ca8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x146cac: 0x443001f  bgezl       $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x146CACu;
    {
        const bool branch_taken_0x146cac = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x146cac) {
            ctx->pc = 0x146CB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146CACu;
            // 0x146cb0: 0xfe820000  sd          $v0, 0x0($s4) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146D2Cu;
            goto label_146d2c;
        }
    }
    ctx->pc = 0x146CB4u;
    // 0x146cb4: 0x8e550098  lw          $s5, 0x98($s2)
    ctx->pc = 0x146cb4u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 152)));
    // 0x146cb8: 0x6a2001c  bltzl       $s5, . + 4 + (0x1C << 2)
    ctx->pc = 0x146CB8u;
    {
        const bool branch_taken_0x146cb8 = (GPR_S64(ctx, 21) < 0);
        if (branch_taken_0x146cb8) {
            ctx->pc = 0x146CBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146CB8u;
            // 0x146cbc: 0xfe820000  sd          $v0, 0x0($s4) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146D2Cu;
            goto label_146d2c;
        }
    }
    ctx->pc = 0x146CC0u;
    // 0x146cc0: 0xde4500a0  ld          $a1, 0xA0($s2)
    ctx->pc = 0x146cc0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 18), 160)));
    // 0x146cc4: 0x8e5600a8  lw          $s6, 0xA8($s2)
    ctx->pc = 0x146cc4u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 168)));
    // 0x146cc8: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x146cc8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x146ccc: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x146cccu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x146cd0: 0xde440090  ld          $a0, 0x90($s2)
    ctx->pc = 0x146cd0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 18), 144)));
    // 0x146cd4: 0x30b10001  andi        $s1, $a1, 0x1
    ctx->pc = 0x146cd4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
    // 0x146cd8: 0x32d00001  andi        $s0, $s6, 0x1
    ctx->pc = 0x146cd8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)1);
    // 0x146cdc: 0x2308024  and         $s0, $s1, $s0
    ctx->pc = 0x146cdcu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 17) & GPR_U64(ctx, 16));
    // 0x146ce0: 0x30820001  andi        $v0, $a0, 0x1
    ctx->pc = 0x146ce0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x146ce4: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x146ce4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x146ce8: 0x10803c  dsll32      $s0, $s0, 0
    ctx->pc = 0x146ce8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x146cec: 0x10803f  dsra32      $s0, $s0, 0
    ctx->pc = 0x146cecu;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 0));
    // 0x146cf0: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x146CF0u;
    SET_GPR_U32(ctx, 31, 0x146CF8u);
    ctx->pc = 0x146CF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146CF0u;
            // 0x146cf4: 0xa0282d  daddu       $a1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146CF8u; }
        if (ctx->pc != 0x146CF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146CF8u; }
        if (ctx->pc != 0x146CF8u) { return; }
    }
    ctx->pc = 0x146CF8u;
label_146cf8:
    // 0x146cf8: 0x217f8  dsll        $v0, $v0, 31
    ctx->pc = 0x146cf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 31);
    // 0x146cfc: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x146cfcu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x146d00: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x146d00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x146d04: 0x2a21021  addu        $v0, $s5, $v0
    ctx->pc = 0x146d04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x146d08: 0xfe820000  sd          $v0, 0x0($s4)
    ctx->pc = 0x146d08u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
    // 0x146d0c: 0xde420090  ld          $v0, 0x90($s2)
    ctx->pc = 0x146d0cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 18), 144)));
    // 0x146d10: 0x2228824  and         $s1, $s1, $v0
    ctx->pc = 0x146d10u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
    // 0x146d14: 0x12200005  beqz        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x146D14u;
    {
        const bool branch_taken_0x146d14 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x146D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146D14u;
            // 0x146d18: 0x26c20001  addiu       $v0, $s6, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146d14) {
            ctx->pc = 0x146D2Cu;
            goto label_146d2c;
        }
    }
    ctx->pc = 0x146D1Cu;
    // 0x146d1c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x146D1Cu;
    {
        const bool branch_taken_0x146d1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146D1Cu;
            // 0x146d20: 0xae4200a8  sw          $v0, 0xA8($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 168), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146d1c) {
            ctx->pc = 0x146D2Cu;
            goto label_146d2c;
        }
    }
    ctx->pc = 0x146D24u;
label_146d24:
    // 0x146d24: 0xde620018  ld          $v0, 0x18($s3)
    ctx->pc = 0x146d24u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x146d28: 0xfe820000  sd          $v0, 0x0($s4)
    ctx->pc = 0x146d28u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
label_146d2c:
    // 0x146d2c: 0x8e430110  lw          $v1, 0x110($s2)
    ctx->pc = 0x146d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 272)));
    // 0x146d30: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x146d30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x146d34: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x146D34u;
    {
        const bool branch_taken_0x146d34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x146d34) {
            ctx->pc = 0x146D38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146D34u;
            // 0x146d38: 0x8e650040  lw          $a1, 0x40($s3) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 64)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146D5Cu;
            goto label_146d5c;
        }
    }
    ctx->pc = 0x146D3Cu;
    // 0x146d3c: 0xde420108  ld          $v0, 0x108($s2)
    ctx->pc = 0x146d3cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 18), 264)));
    // 0x146d40: 0x4420006  bltzl       $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x146D40u;
    {
        const bool branch_taken_0x146d40 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x146d40) {
            ctx->pc = 0x146D44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146D40u;
            // 0x146d44: 0x8e650040  lw          $a1, 0x40($s3) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 64)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146D5Cu;
            goto label_146d5c;
        }
    }
    ctx->pc = 0x146D48u;
    // 0x146d48: 0xfe820000  sd          $v0, 0x0($s4)
    ctx->pc = 0x146d48u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
    // 0x146d4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x146d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x146d50: 0xae400110  sw          $zero, 0x110($s2)
    ctx->pc = 0x146d50u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 272), GPR_U32(ctx, 0));
    // 0x146d54: 0xfe420108  sd          $v0, 0x108($s2)
    ctx->pc = 0x146d54u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 264), GPR_U64(ctx, 2));
    // 0x146d58: 0x8e650040  lw          $a1, 0x40($s3)
    ctx->pc = 0x146d58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 64)));
label_146d5c:
    // 0x146d5c: 0x8e64003c  lw          $a0, 0x3C($s3)
    ctx->pc = 0x146d5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 60)));
    // 0x146d60: 0x8e620034  lw          $v0, 0x34($s3)
    ctx->pc = 0x146d60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 52)));
    // 0x146d64: 0x52978  dsll        $a1, $a1, 5
    ctx->pc = 0x146d64u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 5);
    // 0x146d68: 0x8e660030  lw          $a2, 0x30($s3)
    ctx->pc = 0x146d68u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 48)));
    // 0x146d6c: 0x421b8  dsll        $a0, $a0, 6
    ctx->pc = 0x146d6cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 6);
    // 0x146d70: 0x8e67002c  lw          $a3, 0x2C($s3)
    ctx->pc = 0x146d70u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 44)));
    // 0x146d74: 0xa42825  or          $a1, $a1, $a0
    ctx->pc = 0x146d74u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x146d78: 0x8e630038  lw          $v1, 0x38($s3)
    ctx->pc = 0x146d78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 56)));
    // 0x146d7c: 0x21238  dsll        $v0, $v0, 8
    ctx->pc = 0x146d7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 8);
    // 0x146d80: 0xde640020  ld          $a0, 0x20($s3)
    ctx->pc = 0x146d80u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x146d84: 0x471025  or          $v0, $v0, $a3
    ctx->pc = 0x146d84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
    // 0x146d88: 0x630f8  dsll        $a2, $a2, 3
    ctx->pc = 0x146d88u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 3);
    // 0x146d8c: 0x319f8  dsll        $v1, $v1, 7
    ctx->pc = 0x146d8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 7);
    // 0x146d90: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x146d90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x146d94: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x146d94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x146d98: 0xfee40000  sd          $a0, 0x0($s7)
    ctx->pc = 0x146d98u;
    WRITE64(ADD32(GPR_U32(ctx, 23), 0), GPR_U64(ctx, 4));
    // 0x146d9c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x146d9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x146da0: 0xffc20000  sd          $v0, 0x0($fp)
    ctx->pc = 0x146da0u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 0), GPR_U64(ctx, 2));
    // 0x146da4: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x146da4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x146da8: 0xdfbe0080  ld          $fp, 0x80($sp)
    ctx->pc = 0x146da8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x146dac: 0xdfb70070  ld          $s7, 0x70($sp)
    ctx->pc = 0x146dacu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x146db0: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x146db0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x146db4: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x146db4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x146db8: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x146db8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x146dbc: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x146dbcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x146dc0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x146dc0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x146dc4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x146dc4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146dc8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146dc8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146dcc: 0x3e00008  jr          $ra
    ctx->pc = 0x146DCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146DCCu;
            // 0x146dd0: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146CF8u: goto label_146cf8;
            case 0x146D24u: goto label_146d24;
            case 0x146D2Cu: goto label_146d2c;
            case 0x146D5Cu: goto label_146d5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146DD4u;
    // 0x146dd4: 0x0  nop
    ctx->pc = 0x146dd4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
