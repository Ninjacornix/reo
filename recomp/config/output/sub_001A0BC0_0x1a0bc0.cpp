#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0BC0
// Address: 0x1a0bc0 - 0x1a0cd0
void sub_001A0BC0_0x1a0bc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0BC0_0x1a0bc0");
#endif

    switch (ctx->pc) {
        case 0x1a0cbcu: goto label_1a0cbc;
        default: break;
    }

    ctx->pc = 0x1a0bc0u;

    // 0x1a0bc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a0bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a0bc4: 0x308300ff  andi        $v1, $a0, 0xFF
    ctx->pc = 0x1a0bc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1a0bc8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a0bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0bcc: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1A0BCCu;
    {
        const bool branch_taken_0x1a0bcc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1A0BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0BCCu;
            // 0x1a0bd0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0bcc) {
            ctx->pc = 0x1A0BF4u;
            goto label_1a0bf4;
        }
    }
    ctx->pc = 0x1A0BD4u;
    // 0x1a0bd4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0BD4u;
    {
        const bool branch_taken_0x1a0bd4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0BD4u;
            // 0x1a0bd8: 0x3c020003  lui         $v0, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0bd4) {
            ctx->pc = 0x1A0BE4u;
            goto label_1a0be4;
        }
    }
    ctx->pc = 0x1A0BDCu;
    // 0x1a0bdc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1A0BDCu;
    {
        const bool branch_taken_0x1a0bdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0BDCu;
            // 0x1a0be0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0bdc) {
            ctx->pc = 0x1A0C08u;
            goto label_1a0c08;
        }
    }
    ctx->pc = 0x1A0BE4u;
label_1a0be4:
    // 0x1a0be4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a0be4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a0be8: 0x3442200f  ori         $v0, $v0, 0x200F
    ctx->pc = 0x1a0be8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8207);
    // 0x1a0bec: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A0BECu;
    {
        const bool branch_taken_0x1a0bec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0BECu;
            // 0x1a0bf0: 0xfc220fe0  sd          $v0, 0xFE0($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 4064), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0bec) {
            ctx->pc = 0x1A0C10u;
            goto label_1a0c10;
        }
    }
    ctx->pc = 0x1A0BF4u;
label_1a0bf4:
    // 0x1a0bf4: 0x3c020003  lui         $v0, 0x3
    ctx->pc = 0x1a0bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3 << 16));
    // 0x1a0bf8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a0bf8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a0bfc: 0x34420003  ori         $v0, $v0, 0x3
    ctx->pc = 0x1a0bfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3);
    // 0x1a0c00: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0C00u;
    {
        const bool branch_taken_0x1a0c00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0C00u;
            // 0x1a0c04: 0xfc220fe0  sd          $v0, 0xFE0($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 4064), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0c00) {
            ctx->pc = 0x1A0C10u;
            goto label_1a0c10;
        }
    }
    ctx->pc = 0x1A0C08u;
label_1a0c08:
    // 0x1a0c08: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1A0C08u;
    {
        const bool branch_taken_0x1a0c08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0C08u;
            // 0x1a0c0c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0c08) {
            ctx->pc = 0x1A0CC4u;
            goto label_1a0cc4;
        }
    }
    ctx->pc = 0x1A0C10u;
label_1a0c10:
    // 0x1a0c10: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0c10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0c14: 0x51c02  srl         $v1, $a1, 16
    ctx->pc = 0x1a0c14u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x1a0c18: 0x8c29fd58  lw          $t1, -0x2A8($at)
    ctx->pc = 0x1a0c18u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1a0c1c: 0x51202  srl         $v0, $a1, 8
    ctx->pc = 0x1a0c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 8));
    // 0x1a0c20: 0x306400ff  andi        $a0, $v1, 0xFF
    ctx->pc = 0x1a0c20u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1a0c24: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1a0c24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1a0c28: 0x21a38  dsll        $v1, $v0, 8
    ctx->pc = 0x1a0c28u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 8);
    // 0x1a0c2c: 0x30a200ff  andi        $v0, $a1, 0xFF
    ctx->pc = 0x1a0c2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1a0c30: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1a0c30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a0c34: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1a0c34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1a0c38: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1a0c38u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1a0c3c: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x1a0c3cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a0c40: 0x24840fc0  addiu       $a0, $a0, 0xFC0
    ctx->pc = 0x1a0c40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4032));
    // 0x1a0c44: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0c44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0c48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a0c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0c4c: 0x8c28fd54  lw          $t0, -0x2AC($at)
    ctx->pc = 0x1a0c4cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1a0c50: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1a0c50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a0c54: 0x93100  sll         $a2, $t1, 4
    ctx->pc = 0x1a0c54u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x1a0c58: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a0c58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a0c5c: 0x63438  dsll        $a2, $a2, 16
    ctx->pc = 0x1a0c5cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 16);
    // 0x1a0c60: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a0c60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a0c64: 0x83900  sll         $a3, $t0, 4
    ctx->pc = 0x1a0c64u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 8), 4));
    // 0x1a0c68: 0xfc221000  sd          $v0, 0x1000($at)
    ctx->pc = 0x1a0c68u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4096), GPR_U64(ctx, 2));
    // 0x1a0c6c: 0xe63025  or          $a2, $a3, $a2
    ctx->pc = 0x1a0c6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) | GPR_U64(ctx, 6));
    // 0x1a0c70: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0c74: 0x8c25fed8  lw          $a1, -0x128($at)
    ctx->pc = 0x1a0c74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1a0c78: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0c78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0c7c: 0x1052821  addu        $a1, $t0, $a1
    ctx->pc = 0x1a0c7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1a0c80: 0x8c23fed0  lw          $v1, -0x130($at)
    ctx->pc = 0x1a0c80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966992)));
    // 0x1a0c84: 0x52900  sll         $a1, $a1, 4
    ctx->pc = 0x1a0c84u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1a0c88: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0c88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0c8c: 0x1231821  addu        $v1, $t1, $v1
    ctx->pc = 0x1a0c8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 3)));
    // 0x1a0c90: 0xdc22fdd0  ld          $v0, -0x230($at)
    ctx->pc = 0x1a0c90u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294966736)));
    // 0x1a0c94: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a0c94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a0c98: 0xfc261010  sd          $a2, 0x1010($at)
    ctx->pc = 0x1a0c98u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 6));
    // 0x1a0c9c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a0c9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a0ca0: 0xfc221030  sd          $v0, 0x1030($at)
    ctx->pc = 0x1a0ca0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4144), GPR_U64(ctx, 2));
    // 0x1a0ca4: 0x31100  sll         $v0, $v1, 4
    ctx->pc = 0x1a0ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a0ca8: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a0ca8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a0cac: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1a0cacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1a0cb0: 0xa21025  or          $v0, $a1, $v0
    ctx->pc = 0x1a0cb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1a0cb4: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1A0CB4u;
    SET_GPR_U32(ctx, 31, 0x1A0CBCu);
    ctx->pc = 0x1A0CB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0CB4u;
            // 0x1a0cb8: 0xfc221020  sd          $v0, 0x1020($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 4128), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0CBCu; }
        if (ctx->pc != 0x1A0CBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0CBCu; }
        if (ctx->pc != 0x1A0CBCu) { return; }
    }
    ctx->pc = 0x1A0CBCu;
label_1a0cbc:
    // 0x1a0cbc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a0cbcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0cc0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a0cc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a0cc4:
    // 0x1a0cc4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A0CC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0CC4u;
            // 0x1a0cc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0BE4u: goto label_1a0be4;
            case 0x1A0BF4u: goto label_1a0bf4;
            case 0x1A0C08u: goto label_1a0c08;
            case 0x1A0C10u: goto label_1a0c10;
            case 0x1A0CBCu: goto label_1a0cbc;
            case 0x1A0CC4u: goto label_1a0cc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A0CCCu;
    // 0x1a0ccc: 0x0  nop
    ctx->pc = 0x1a0cccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
