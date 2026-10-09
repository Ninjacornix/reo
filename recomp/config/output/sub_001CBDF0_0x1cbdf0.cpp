#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBDF0
// Address: 0x1cbdf0 - 0x1cc000
void sub_001CBDF0_0x1cbdf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBDF0_0x1cbdf0");
#endif

    switch (ctx->pc) {
        case 0x1cbe60u: goto label_1cbe60;
        case 0x1cbf00u: goto label_1cbf00;
        case 0x1cbf8cu: goto label_1cbf8c;
        case 0x1cbfa4u: goto label_1cbfa4;
        case 0x1cbfbcu: goto label_1cbfbc;
        case 0x1cbfd4u: goto label_1cbfd4;
        case 0x1cbfecu: goto label_1cbfec;
        case 0x1cbff4u: goto label_1cbff4;
        default: break;
    }

    ctx->pc = 0x1cbdf0u;

label_1cbdf0:
    // 0x1cbdf0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbdf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbdf4: 0x8045190  j           func_114640
    ctx->pc = 0x1CBDF4u;
    ctx->pc = 0x1CBDF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBDF4u;
            // 0x1cbdf8: 0x8c245fe8  lw          $a0, 0x5FE8($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24552)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1CBDFCu;
    // 0x1cbdfc: 0x0  nop
    ctx->pc = 0x1cbdfcu;
    // NOP
    // 0x1cbe00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cbe00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cbe04: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbe04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cbe08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cbe0c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cbe0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cbe10: 0x8c23d9f8  lw          $v1, -0x2608($at)
    ctx->pc = 0x1cbe10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957560)));
    // 0x1cbe14: 0x1460001e  bnez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1CBE14u;
    {
        const bool branch_taken_0x1cbe14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CBE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBE14u;
            // 0x1cbe18: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbe14) {
            ctx->pc = 0x1CBE90u;
            goto label_1cbe90;
        }
    }
    ctx->pc = 0x1CBE1Cu;
    // 0x1cbe1c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbe1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe20: 0x8c23da00  lw          $v1, -0x2600($at)
    ctx->pc = 0x1cbe20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbe24: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBE24u;
    {
        const bool branch_taken_0x1cbe24 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbe24) {
            ctx->pc = 0x1CBE34u;
            goto label_1cbe34;
        }
    }
    ctx->pc = 0x1CBE2Cu;
    // 0x1cbe2c: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1CBE2Cu;
    {
        const bool branch_taken_0x1cbe2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBE2Cu;
            // 0x1cbe30: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbe2c) {
            ctx->pc = 0x1CBE94u;
            goto label_1cbe94;
        }
    }
    ctx->pc = 0x1CBE34u;
label_1cbe34:
    // 0x1cbe34: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbe34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbe38: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1cbe38u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe3c: 0x96060004  lhu         $a2, 0x4($s0)
    ctx->pc = 0x1cbe3cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbe40: 0x24630a20  addiu       $v1, $v1, 0xA20
    ctx->pc = 0x1cbe40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2592));
    // 0x1cbe44: 0x8c245ff0  lw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbe44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24560)));
    // 0x1cbe48: 0x863821  addu        $a3, $a0, $a2
    ctx->pc = 0x1cbe48u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1cbe4c: 0xe3082b  sltu        $at, $a3, $v1
    ctx->pc = 0x1cbe4cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1cbe50: 0x1020000f  beqz        $at, . + 4 + (0xF << 2)
    ctx->pc = 0x1CBE50u;
    {
        const bool branch_taken_0x1cbe50 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbe50) {
            ctx->pc = 0x1CBE90u;
            goto label_1cbe90;
        }
    }
    ctx->pc = 0x1CBE58u;
    // 0x1cbe58: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1CBE58u;
    SET_GPR_U32(ctx, 31, 0x1CBE60u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBE60u; }
        if (ctx->pc != 0x1CBE60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBE60u; }
        if (ctx->pc != 0x1CBE60u) { return; }
    }
    ctx->pc = 0x1CBE60u;
label_1cbe60:
    // 0x1cbe60: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbe60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbe64: 0x96050004  lhu         $a1, 0x4($s0)
    ctx->pc = 0x1cbe64u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbe68: 0x8c245ff0  lw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbe68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24560)));
    // 0x1cbe6c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbe6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe70: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1cbe70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1cbe74: 0x8c23d9f0  lw          $v1, -0x2610($at)
    ctx->pc = 0x1cbe74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957552)));
    // 0x1cbe78: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbe78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbe7c: 0xac245ff0  sw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbe7cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24560), GPR_U32(ctx, 4));
    // 0x1cbe80: 0x96040004  lhu         $a0, 0x4($s0)
    ctx->pc = 0x1cbe80u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbe84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbe84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe88: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1cbe88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1cbe8c: 0xac23d9f0  sw          $v1, -0x2610($at)
    ctx->pc = 0x1cbe8cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957552), GPR_U32(ctx, 3));
label_1cbe90:
    // 0x1cbe90: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cbe90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1cbe94:
    // 0x1cbe94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbe94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbe98: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBE98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBE9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBE98u;
            // 0x1cbe9c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBDF0u: goto label_1cbdf0;
            case 0x1CBE34u: goto label_1cbe34;
            case 0x1CBE60u: goto label_1cbe60;
            case 0x1CBE90u: goto label_1cbe90;
            case 0x1CBE94u: goto label_1cbe94;
            case 0x1CBED4u: goto label_1cbed4;
            case 0x1CBF00u: goto label_1cbf00;
            case 0x1CBF30u: goto label_1cbf30;
            case 0x1CBF34u: goto label_1cbf34;
            case 0x1CBF8Cu: goto label_1cbf8c;
            case 0x1CBFA4u: goto label_1cbfa4;
            case 0x1CBFBCu: goto label_1cbfbc;
            case 0x1CBFD4u: goto label_1cbfd4;
            case 0x1CBFECu: goto label_1cbfec;
            case 0x1CBFF4u: goto label_1cbff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBEA0u;
    // 0x1cbea0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cbea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cbea4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbea4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbea8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cbea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cbeac: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cbeacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cbeb0: 0x8c23d9f8  lw          $v1, -0x2608($at)
    ctx->pc = 0x1cbeb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957560)));
    // 0x1cbeb4: 0x1460001e  bnez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1CBEB4u;
    {
        const bool branch_taken_0x1cbeb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CBEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBEB4u;
            // 0x1cbeb8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbeb4) {
            ctx->pc = 0x1CBF30u;
            goto label_1cbf30;
        }
    }
    ctx->pc = 0x1CBEBCu;
    // 0x1cbebc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbebcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbec0: 0x8c23da00  lw          $v1, -0x2600($at)
    ctx->pc = 0x1cbec0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbec4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBEC4u;
    {
        const bool branch_taken_0x1cbec4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbec4) {
            ctx->pc = 0x1CBED4u;
            goto label_1cbed4;
        }
    }
    ctx->pc = 0x1CBECCu;
    // 0x1cbecc: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1CBECCu;
    {
        const bool branch_taken_0x1cbecc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBECCu;
            // 0x1cbed0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbecc) {
            ctx->pc = 0x1CBF34u;
            goto label_1cbf34;
        }
    }
    ctx->pc = 0x1CBED4u;
label_1cbed4:
    // 0x1cbed4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbed4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbed8: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1cbed8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1cbedc: 0x96060004  lhu         $a2, 0x4($s0)
    ctx->pc = 0x1cbedcu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbee0: 0x24630a20  addiu       $v1, $v1, 0xA20
    ctx->pc = 0x1cbee0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2592));
    // 0x1cbee4: 0x8c245ff0  lw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbee4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24560)));
    // 0x1cbee8: 0x863821  addu        $a3, $a0, $a2
    ctx->pc = 0x1cbee8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1cbeec: 0xe3082b  sltu        $at, $a3, $v1
    ctx->pc = 0x1cbeecu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1cbef0: 0x1020000f  beqz        $at, . + 4 + (0xF << 2)
    ctx->pc = 0x1CBEF0u;
    {
        const bool branch_taken_0x1cbef0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbef0) {
            ctx->pc = 0x1CBF30u;
            goto label_1cbf30;
        }
    }
    ctx->pc = 0x1CBEF8u;
    // 0x1cbef8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1CBEF8u;
    SET_GPR_U32(ctx, 31, 0x1CBF00u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBF00u; }
        if (ctx->pc != 0x1CBF00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBF00u; }
        if (ctx->pc != 0x1CBF00u) { return; }
    }
    ctx->pc = 0x1CBF00u;
label_1cbf00:
    // 0x1cbf00: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbf00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbf04: 0x96050004  lhu         $a1, 0x4($s0)
    ctx->pc = 0x1cbf04u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbf08: 0x8c245ff0  lw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbf08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24560)));
    // 0x1cbf0c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf10: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1cbf10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1cbf14: 0x8c23d9f0  lw          $v1, -0x2610($at)
    ctx->pc = 0x1cbf14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957552)));
    // 0x1cbf18: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbf18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbf1c: 0xac245ff0  sw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbf1cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24560), GPR_U32(ctx, 4));
    // 0x1cbf20: 0x96040004  lhu         $a0, 0x4($s0)
    ctx->pc = 0x1cbf20u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbf24: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf28: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1cbf28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1cbf2c: 0xac23d9f0  sw          $v1, -0x2610($at)
    ctx->pc = 0x1cbf2cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957552), GPR_U32(ctx, 3));
label_1cbf30:
    // 0x1cbf30: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cbf30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1cbf34:
    // 0x1cbf34: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbf34u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbf38: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBF38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBF3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBF38u;
            // 0x1cbf3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBDF0u: goto label_1cbdf0;
            case 0x1CBE34u: goto label_1cbe34;
            case 0x1CBE60u: goto label_1cbe60;
            case 0x1CBE90u: goto label_1cbe90;
            case 0x1CBE94u: goto label_1cbe94;
            case 0x1CBED4u: goto label_1cbed4;
            case 0x1CBF00u: goto label_1cbf00;
            case 0x1CBF30u: goto label_1cbf30;
            case 0x1CBF34u: goto label_1cbf34;
            case 0x1CBF8Cu: goto label_1cbf8c;
            case 0x1CBFA4u: goto label_1cbfa4;
            case 0x1CBFBCu: goto label_1cbfbc;
            case 0x1CBFD4u: goto label_1cbfd4;
            case 0x1CBFECu: goto label_1cbfec;
            case 0x1CBFF4u: goto label_1cbff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBF40u;
    // 0x1cbf40: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBF40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBDF0u: goto label_1cbdf0;
            case 0x1CBE34u: goto label_1cbe34;
            case 0x1CBE60u: goto label_1cbe60;
            case 0x1CBE90u: goto label_1cbe90;
            case 0x1CBE94u: goto label_1cbe94;
            case 0x1CBED4u: goto label_1cbed4;
            case 0x1CBF00u: goto label_1cbf00;
            case 0x1CBF30u: goto label_1cbf30;
            case 0x1CBF34u: goto label_1cbf34;
            case 0x1CBF8Cu: goto label_1cbf8c;
            case 0x1CBFA4u: goto label_1cbfa4;
            case 0x1CBFBCu: goto label_1cbfbc;
            case 0x1CBFD4u: goto label_1cbfd4;
            case 0x1CBFECu: goto label_1cbfec;
            case 0x1CBFF4u: goto label_1cbff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBF48u;
    // 0x1cbf48: 0x0  nop
    ctx->pc = 0x1cbf48u;
    // NOP
    // 0x1cbf4c: 0x0  nop
    ctx->pc = 0x1cbf4cu;
    // NOP
    // 0x1cbf50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cbf50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cbf54: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cbf54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cbf58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cbf5c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf60: 0xac20d9f0  sw          $zero, -0x2610($at)
    ctx->pc = 0x1cbf60u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957552), GPR_U32(ctx, 0));
    // 0x1cbf64: 0x2442fa20  addiu       $v0, $v0, -0x5E0
    ctx->pc = 0x1cbf64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965792));
    // 0x1cbf68: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf6c: 0xac20d9f8  sw          $zero, -0x2608($at)
    ctx->pc = 0x1cbf6cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957560), GPR_U32(ctx, 0));
    // 0x1cbf70: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbf70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbf74: 0xac225ff0  sw          $v0, 0x5FF0($at)
    ctx->pc = 0x1cbf74u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24560), GPR_U32(ctx, 2));
    // 0x1cbf78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf7c: 0xac20da00  sw          $zero, -0x2600($at)
    ctx->pc = 0x1cbf7cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957568), GPR_U32(ctx, 0));
    // 0x1cbf80: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf84: 0xc072f78  jal         func_1CBDE0
    ctx->pc = 0x1CBF84u;
    SET_GPR_U32(ctx, 31, 0x1CBF8Cu);
    ctx->pc = 0x1CBF88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBF84u;
            // 0x1cbf88: 0xa020fa10  sb          $zero, -0x5F0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294965776), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBDE0u;
    if (runtime->hasFunction(0x1CBDE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBF8Cu; }
        if (ctx->pc != 0x1CBF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDE0_0x1cbde0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBF8Cu; }
        if (ctx->pc != 0x1CBF8Cu) { return; }
    }
    ctx->pc = 0x1CBF8Cu;
label_1cbf8c:
    // 0x1cbf8c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf90: 0x3c06001d  lui         $a2, 0x1D
    ctx->pc = 0x1cbf90u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)29 << 16));
    // 0x1cbf94: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbf94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbf98: 0x24050012  addiu       $a1, $zero, 0x12
    ctx->pc = 0x1cbf98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1cbf9c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1CBF9Cu;
    SET_GPR_U32(ctx, 31, 0x1CBFA4u);
    ctx->pc = 0x1CBFA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBF9Cu;
            // 0x1cbfa0: 0x24c6be00  addiu       $a2, $a2, -0x4200 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294950400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFA4u; }
        if (ctx->pc != 0x1CBFA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFA4u; }
        if (ctx->pc != 0x1CBFA4u) { return; }
    }
    ctx->pc = 0x1CBFA4u;
label_1cbfa4:
    // 0x1cbfa4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbfa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbfa8: 0x3c06001d  lui         $a2, 0x1D
    ctx->pc = 0x1cbfa8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)29 << 16));
    // 0x1cbfac: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbfacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbfb0: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x1cbfb0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1cbfb4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1CBFB4u;
    SET_GPR_U32(ctx, 31, 0x1CBFBCu);
    ctx->pc = 0x1CBFB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBFB4u;
            // 0x1cbfb8: 0x24c6bea0  addiu       $a2, $a2, -0x4160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294950560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFBCu; }
        if (ctx->pc != 0x1CBFBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFBCu; }
        if (ctx->pc != 0x1CBFBCu) { return; }
    }
    ctx->pc = 0x1CBFBCu;
label_1cbfbc:
    // 0x1cbfbc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbfbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbfc0: 0x3c06001d  lui         $a2, 0x1D
    ctx->pc = 0x1cbfc0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)29 << 16));
    // 0x1cbfc4: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbfc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbfc8: 0x24050013  addiu       $a1, $zero, 0x13
    ctx->pc = 0x1cbfc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1cbfcc: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1CBFCCu;
    SET_GPR_U32(ctx, 31, 0x1CBFD4u);
    ctx->pc = 0x1CBFD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBFCCu;
            // 0x1cbfd0: 0x24c6bf40  addiu       $a2, $a2, -0x40C0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294950720));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFD4u; }
        if (ctx->pc != 0x1CBFD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFD4u; }
        if (ctx->pc != 0x1CBFD4u) { return; }
    }
    ctx->pc = 0x1CBFD4u;
label_1cbfd4:
    // 0x1cbfd4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbfd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbfd8: 0x3c06001d  lui         $a2, 0x1D
    ctx->pc = 0x1cbfd8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)29 << 16));
    // 0x1cbfdc: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbfdcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbfe0: 0x24050015  addiu       $a1, $zero, 0x15
    ctx->pc = 0x1cbfe0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1cbfe4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1CBFE4u;
    SET_GPR_U32(ctx, 31, 0x1CBFECu);
    ctx->pc = 0x1CBFE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBFE4u;
            // 0x1cbfe8: 0x24c6bf40  addiu       $a2, $a2, -0x40C0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294950720));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFECu; }
        if (ctx->pc != 0x1CBFECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFECu; }
        if (ctx->pc != 0x1CBFECu) { return; }
    }
    ctx->pc = 0x1CBFECu;
label_1cbfec:
    // 0x1cbfec: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CBFECu;
    SET_GPR_U32(ctx, 31, 0x1CBFF4u);
    ctx->pc = 0x1CBDF0u;
    goto label_1cbdf0;
    ctx->pc = 0x1CBFF4u;
label_1cbff4:
    // 0x1cbff4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cbff4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbff8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBFF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBFFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBFF8u;
            // 0x1cbffc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBDF0u: goto label_1cbdf0;
            case 0x1CBE34u: goto label_1cbe34;
            case 0x1CBE60u: goto label_1cbe60;
            case 0x1CBE90u: goto label_1cbe90;
            case 0x1CBE94u: goto label_1cbe94;
            case 0x1CBED4u: goto label_1cbed4;
            case 0x1CBF00u: goto label_1cbf00;
            case 0x1CBF30u: goto label_1cbf30;
            case 0x1CBF34u: goto label_1cbf34;
            case 0x1CBF8Cu: goto label_1cbf8c;
            case 0x1CBFA4u: goto label_1cbfa4;
            case 0x1CBFBCu: goto label_1cbfbc;
            case 0x1CBFD4u: goto label_1cbfd4;
            case 0x1CBFECu: goto label_1cbfec;
            case 0x1CBFF4u: goto label_1cbff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC000u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
