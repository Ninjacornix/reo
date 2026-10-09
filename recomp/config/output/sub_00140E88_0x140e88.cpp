#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140E88
// Address: 0x140e88 - 0x141280
void sub_00140E88_0x140e88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140E88_0x140e88");
#endif

    switch (ctx->pc) {
        case 0x140ebcu: goto label_140ebc;
        case 0x140f30u: goto label_140f30;
        case 0x140f58u: goto label_140f58;
        case 0x140f68u: goto label_140f68;
        case 0x140f94u: goto label_140f94;
        case 0x140ff8u: goto label_140ff8;
        case 0x141000u: goto label_141000;
        case 0x141020u: goto label_141020;
        case 0x141074u: goto label_141074;
        case 0x141098u: goto label_141098;
        case 0x1410e0u: goto label_1410e0;
        case 0x141108u: goto label_141108;
        case 0x141110u: goto label_141110;
        case 0x141138u: goto label_141138;
        case 0x141198u: goto label_141198;
        case 0x1411a0u: goto label_1411a0;
        case 0x1411c0u: goto label_1411c0;
        case 0x141214u: goto label_141214;
        case 0x141238u: goto label_141238;
        default: break;
    }

    ctx->pc = 0x140e88u;

    // 0x140e88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140e88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140e8c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x140e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x140e90: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140e94: 0x24509a74  addiu       $s0, $v0, -0x658C
    ctx->pc = 0x140e94u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941300));
    // 0x140e98: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140e9c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x140e9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x140ea0: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x140ea0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140ea4: 0x24639a70  addiu       $v1, $v1, -0x6590
    ctx->pc = 0x140ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941296));
    // 0x140ea8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x140ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140eac: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x140EACu;
    {
        const bool branch_taken_0x140eac = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x140EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140EACu;
            // 0x140eb0: 0x24820001  addiu       $v0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140eac) {
            ctx->pc = 0x140EC4u;
            goto label_140ec4;
        }
    }
    ctx->pc = 0x140EB4u;
    // 0x140eb4: 0xc04e4be  jal         func_1392F8
    ctx->pc = 0x140EB4u;
    SET_GPR_U32(ctx, 31, 0x140EBCu);
    ctx->pc = 0x1392F8u;
    if (runtime->hasFunction(0x1392F8u)) {
        auto targetFn = runtime->lookupFunction(0x1392F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140EBCu; }
        if (ctx->pc != 0x140EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001392F8_0x1392f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140EBCu; }
        if (ctx->pc != 0x140EBCu) { return; }
    }
    ctx->pc = 0x140EBCu;
label_140ebc:
    // 0x140ebc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x140ebcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140ec0: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x140ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_140ec4:
    // 0x140ec4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140ec4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140ec8: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x140ec8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x140ecc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140eccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140ed0: 0x3e00008  jr          $ra
    ctx->pc = 0x140ED0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140ED0u;
            // 0x140ed4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140EBCu: goto label_140ebc;
            case 0x140EC4u: goto label_140ec4;
            case 0x140F08u: goto label_140f08;
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140ED8u;
    // 0x140ed8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140ed8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140edc: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x140edcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x140ee0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x140ee4: 0x24639a74  addiu       $v1, $v1, -0x658C
    ctx->pc = 0x140ee4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941300));
    // 0x140ee8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x140ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140eec: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x140eecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x140ef0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x140EF0u;
    {
        const bool branch_taken_0x140ef0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x140EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140EF0u;
            // 0x140ef4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140ef0) {
            ctx->pc = 0x140F08u;
            goto label_140f08;
        }
    }
    ctx->pc = 0x140EF8u;
    // 0x140ef8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140ef8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140efc: 0x804e4fa  j           func_1393E8
    ctx->pc = 0x140EFCu;
    ctx->pc = 0x140F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140EFCu;
            // 0x140f00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1393E8u;
    if (runtime->hasFunction(0x1393E8u)) {
        auto targetFn = runtime->lookupFunction(0x1393E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001393E8_0x1393e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140F04u;
    // 0x140f04: 0x0  nop
    ctx->pc = 0x140f04u;
    // NOP
label_140f08:
    // 0x140f08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140f08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140f0c: 0x3e00008  jr          $ra
    ctx->pc = 0x140F0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140F0Cu;
            // 0x140f10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140EBCu: goto label_140ebc;
            case 0x140EC4u: goto label_140ec4;
            case 0x140F08u: goto label_140f08;
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140F14u;
    // 0x140f14: 0x0  nop
    ctx->pc = 0x140f14u;
    // NOP
    // 0x140f18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140f18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x140f1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140f1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140f20: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x140f20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140f24: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x140f24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140f28: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x140F28u;
    {
        const bool branch_taken_0x140f28 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x140F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140F28u;
            // 0x140f2c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140f28) {
            ctx->pc = 0x140F50u;
            goto label_140f50;
        }
    }
    ctx->pc = 0x140F30u;
label_140f30:
    // 0x140f30: 0x0  nop
    ctx->pc = 0x140f30u;
    // NOP
    // 0x140f34: 0x0  nop
    ctx->pc = 0x140f34u;
    // NOP
    // 0x140f38: 0x0  nop
    ctx->pc = 0x140f38u;
    // NOP
    // 0x140f3c: 0x0  nop
    ctx->pc = 0x140f3cu;
    // NOP
    // 0x140f40: 0x0  nop
    ctx->pc = 0x140f40u;
    // NOP
    // 0x140f44: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x140F44u;
    {
        const bool branch_taken_0x140f44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x140f44) {
            ctx->pc = 0x140F30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140f30;
        }
    }
    ctx->pc = 0x140F4Cu;
    // 0x140f4c: 0x0  nop
    ctx->pc = 0x140f4cu;
    // NOP
label_140f50:
    // 0x140f50: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x140F50u;
    SET_GPR_U32(ctx, 31, 0x140F58u);
    ctx->pc = 0x140F54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140F50u;
            // 0x140f54: 0x8e110000  lw          $s1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140F58u; }
        if (ctx->pc != 0x140F58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140F58u; }
        if (ctx->pc != 0x140F58u) { return; }
    }
    ctx->pc = 0x140F58u;
label_140f58:
    // 0x140f58: 0x5a200012  blezl       $s1, . + 4 + (0x12 << 2)
    ctx->pc = 0x140F58u;
    {
        const bool branch_taken_0x140f58 = (GPR_S64(ctx, 17) <= 0);
        if (branch_taken_0x140f58) {
            ctx->pc = 0x140F5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140F58u;
            // 0x140f5c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140FA4u;
            goto label_140fa4;
        }
    }
    ctx->pc = 0x140F60u;
    // 0x140f60: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x140f60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140f64: 0x0  nop
    ctx->pc = 0x140f64u;
    // NOP
label_140f68:
    // 0x140f68: 0x24b00010  addiu       $s0, $a1, 0x10
    ctx->pc = 0x140f68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x140f6c: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x140f6cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140f70: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x140F70u;
    {
        const bool branch_taken_0x140f70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x140f70) {
            ctx->pc = 0x140F74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140F70u;
            // 0x140f74: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140F98u;
            goto label_140f98;
        }
    }
    ctx->pc = 0x140F78u;
    // 0x140f78: 0x8ca20014  lw          $v0, 0x14($a1)
    ctx->pc = 0x140f78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x140f7c: 0x24a60018  addiu       $a2, $a1, 0x18
    ctx->pc = 0x140f7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 24));
    // 0x140f80: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x140f80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x140f84: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x140f84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x140f88: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x140f88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x140f8c: 0x40f809  jalr        $v0
    ctx->pc = 0x140F8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140F94u);
        ctx->pc = 0x140F90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140F8Cu;
            // 0x140f90: 0x80a50011  lb          $a1, 0x11($a1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 17)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140F94u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140EBCu: goto label_140ebc;
            case 0x140EC4u: goto label_140ec4;
            case 0x140F08u: goto label_140f08;
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140F94u; }
            if (ctx->pc != 0x140F94u) { return; }
        }
        }
    }
    ctx->pc = 0x140F94u;
label_140f94:
    // 0x140f94: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x140f94u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_140f98:
    // 0x140f98: 0x1620fff3  bnez        $s1, . + 4 + (-0xD << 2)
    ctx->pc = 0x140F98u;
    {
        const bool branch_taken_0x140f98 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x140F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140F98u;
            // 0x140f9c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140f98) {
            ctx->pc = 0x140F68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140f68;
        }
    }
    ctx->pc = 0x140FA0u;
    // 0x140fa0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_140fa4:
    // 0x140fa4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140fa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140fa8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x140fa8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140fac: 0x804fc9c  j           func_13F270
    ctx->pc = 0x140FACu;
    ctx->pc = 0x140FB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140FACu;
            // 0x140fb0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140FB4u;
    // 0x140fb4: 0x0  nop
    ctx->pc = 0x140fb4u;
    // NOP
    // 0x140fb8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x140fb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x140fbc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x140fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x140fc0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x140fc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x140fc4: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x140fc4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140fc8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x140fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x140fcc: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x140fccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140fd0: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x140fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x140fd4: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x140fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x140fd8: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x140fd8u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140fdc: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x140fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x140fe0: 0x24170001  addiu       $s7, $zero, 0x1
    ctx->pc = 0x140fe0u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140fe4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x140fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x140fe8: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x140fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x140fec: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x140fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x140ff0: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x140FF0u;
    SET_GPR_U32(ctx, 31, 0x140FF8u);
    ctx->pc = 0x140FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140FF0u;
            // 0x140ff4: 0x26d50010  addiu       $s5, $s6, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 22), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140FF8u; }
        if (ctx->pc != 0x140FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140FF8u; }
        if (ctx->pc != 0x140FF8u) { return; }
    }
    ctx->pc = 0x140FF8u;
label_140ff8:
    // 0x140ff8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x140ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x140ffc: 0x24519a90  addiu       $s1, $v0, -0x6570
    ctx->pc = 0x140ffcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941328));
label_141000:
    // 0x141000: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x141000u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x141004: 0x5457001f  bnel        $v0, $s7, . + 4 + (0x1F << 2)
    ctx->pc = 0x141004u;
    {
        const bool branch_taken_0x141004 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 23));
        if (branch_taken_0x141004) {
            ctx->pc = 0x141008u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141004u;
            // 0x141008: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141084u;
            goto label_141084;
        }
    }
    ctx->pc = 0x14100Cu;
    // 0x14100c: 0x121100  sll         $v0, $s2, 4
    ctx->pc = 0x14100cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x141010: 0x24140080  addiu       $s4, $zero, 0x80
    ctx->pc = 0x141010u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x141014: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x141014u;
    {
        const bool branch_taken_0x141014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x141018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141014u;
            // 0x141018: 0x558021  addu        $s0, $v0, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141014) {
            ctx->pc = 0x141050u;
            goto label_141050;
        }
    }
    ctx->pc = 0x14101Cu;
    // 0x14101c: 0x0  nop
    ctx->pc = 0x14101cu;
    // NOP
label_141020:
    // 0x141020: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x141020u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x141024: 0x9222000c  lbu         $v0, 0xC($s1)
    ctx->pc = 0x141024u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x141028: 0x8e230010  lw          $v1, 0x10($s1)
    ctx->pc = 0x141028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x14102c: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x14102cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x141030: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x141030u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x141034: 0x96220002  lhu         $v0, 0x2($s1)
    ctx->pc = 0x141034u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x141038: 0x6ba30007  ldl         $v1, 0x7($sp)
    ctx->pc = 0x141038u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x14103c: 0x6fa30000  ldr         $v1, 0x0($sp)
    ctx->pc = 0x14103cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x141040: 0xb203000f  sdl         $v1, 0xF($s0)
    ctx->pc = 0x141040u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x141044: 0xb6030008  sdr         $v1, 0x8($s0)
    ctx->pc = 0x141044u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x141048: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x141048u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14104c: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x14104cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
label_141050:
    // 0x141050: 0x1254000f  beq         $s2, $s4, . + 4 + (0xF << 2)
    ctx->pc = 0x141050u;
    {
        const bool branch_taken_0x141050 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 20));
        ctx->pc = 0x141054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141050u;
            // 0x141054: 0x3c067fff  lui         $a2, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141050) {
            ctx->pc = 0x141090u;
            goto label_141090;
        }
    }
    ctx->pc = 0x141058u;
    // 0x141058: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x141058u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x14105c: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x14105cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x141060: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x141060u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x141064: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x141064u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x141068: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x141068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x14106c: 0x40f809  jalr        $v0
    ctx->pc = 0x14106Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141074u);
        ctx->pc = 0x141070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14106Cu;
            // 0x141070: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141074u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140EBCu: goto label_140ebc;
            case 0x140EC4u: goto label_140ec4;
            case 0x140F08u: goto label_140f08;
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141074u; }
            if (ctx->pc != 0x141074u) { return; }
        }
        }
    }
    ctx->pc = 0x141074u;
label_141074:
    // 0x141074: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x141074u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x141078: 0x5460ffe9  bnel        $v1, $zero, . + 4 + (-0x17 << 2)
    ctx->pc = 0x141078u;
    {
        const bool branch_taken_0x141078 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x141078) {
            ctx->pc = 0x14107Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141078u;
            // 0x14107c: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141020u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141020;
        }
    }
    ctx->pc = 0x141080u;
    // 0x141080: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x141080u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_141084:
    // 0x141084: 0x2a620020  slti        $v0, $s3, 0x20
    ctx->pc = 0x141084u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x141088: 0x1440ffdd  bnez        $v0, . + 4 + (-0x23 << 2)
    ctx->pc = 0x141088u;
    {
        const bool branch_taken_0x141088 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14108Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141088u;
            // 0x14108c: 0x26310014  addiu       $s1, $s1, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141088) {
            ctx->pc = 0x141000u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141000;
        }
    }
    ctx->pc = 0x141090u;
label_141090:
    // 0x141090: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x141090u;
    SET_GPR_U32(ctx, 31, 0x141098u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141098u; }
        if (ctx->pc != 0x141098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141098u; }
        if (ctx->pc != 0x141098u) { return; }
    }
    ctx->pc = 0x141098u;
label_141098:
    // 0x141098: 0xaed20000  sw          $s2, 0x0($s6)
    ctx->pc = 0x141098u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 18));
    // 0x14109c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x14109cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1410a0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1410a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1410a4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1410a4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1410a8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1410a8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1410ac: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x1410acu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1410b0: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1410b0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1410b4: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x1410b4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1410b8: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x1410b8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1410bc: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1410bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1410c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1410C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1410C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1410C0u;
            // 0x1410c4: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140EBCu: goto label_140ebc;
            case 0x140EC4u: goto label_140ec4;
            case 0x140F08u: goto label_140f08;
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1410C8u;
    // 0x1410c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1410c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1410cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1410ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1410d0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1410d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1410d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1410d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1410d8: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1410D8u;
    {
        const bool branch_taken_0x1410d8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1410DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1410D8u;
            // 0x1410dc: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1410d8) {
            ctx->pc = 0x141100u;
            goto label_141100;
        }
    }
    ctx->pc = 0x1410E0u;
label_1410e0:
    // 0x1410e0: 0x0  nop
    ctx->pc = 0x1410e0u;
    // NOP
    // 0x1410e4: 0x0  nop
    ctx->pc = 0x1410e4u;
    // NOP
    // 0x1410e8: 0x0  nop
    ctx->pc = 0x1410e8u;
    // NOP
    // 0x1410ec: 0x0  nop
    ctx->pc = 0x1410ecu;
    // NOP
    // 0x1410f0: 0x0  nop
    ctx->pc = 0x1410f0u;
    // NOP
    // 0x1410f4: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1410F4u;
    {
        const bool branch_taken_0x1410f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1410f4) {
            ctx->pc = 0x1410E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1410e0;
        }
    }
    ctx->pc = 0x1410FCu;
    // 0x1410fc: 0x0  nop
    ctx->pc = 0x1410fcu;
    // NOP
label_141100:
    // 0x141100: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x141100u;
    SET_GPR_U32(ctx, 31, 0x141108u);
    ctx->pc = 0x141104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141100u;
            // 0x141104: 0x8e110000  lw          $s1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141108u; }
        if (ctx->pc != 0x141108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141108u; }
        if (ctx->pc != 0x141108u) { return; }
    }
    ctx->pc = 0x141108u;
label_141108:
    // 0x141108: 0x5a20000f  blezl       $s1, . + 4 + (0xF << 2)
    ctx->pc = 0x141108u;
    {
        const bool branch_taken_0x141108 = (GPR_S64(ctx, 17) <= 0);
        if (branch_taken_0x141108) {
            ctx->pc = 0x14110Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141108u;
            // 0x14110c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141148u;
            goto label_141148;
        }
    }
    ctx->pc = 0x141110u;
label_141110:
    // 0x141110: 0x82020010  lb          $v0, 0x10($s0)
    ctx->pc = 0x141110u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x141114: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x141114u;
    {
        const bool branch_taken_0x141114 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x141114) {
            ctx->pc = 0x141118u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141114u;
            // 0x141118: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14113Cu;
            goto label_14113c;
        }
    }
    ctx->pc = 0x14111Cu;
    // 0x14111c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x14111cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x141120: 0x26060018  addiu       $a2, $s0, 0x18
    ctx->pc = 0x141120u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x141124: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x141124u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x141128: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x141128u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14112c: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x14112cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x141130: 0x40f809  jalr        $v0
    ctx->pc = 0x141130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141138u);
        ctx->pc = 0x141134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141130u;
            // 0x141134: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141138u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140EBCu: goto label_140ebc;
            case 0x140EC4u: goto label_140ec4;
            case 0x140F08u: goto label_140f08;
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141138u; }
            if (ctx->pc != 0x141138u) { return; }
        }
        }
    }
    ctx->pc = 0x141138u;
label_141138:
    // 0x141138: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x141138u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_14113c:
    // 0x14113c: 0x1620fff4  bnez        $s1, . + 4 + (-0xC << 2)
    ctx->pc = 0x14113Cu;
    {
        const bool branch_taken_0x14113c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x141140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14113Cu;
            // 0x141140: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14113c) {
            ctx->pc = 0x141110u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141110;
        }
    }
    ctx->pc = 0x141144u;
    // 0x141144: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141144u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_141148:
    // 0x141148: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141148u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14114c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x14114cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141150: 0x804fc9c  j           func_13F270
    ctx->pc = 0x141150u;
    ctx->pc = 0x141154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141150u;
            // 0x141154: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141158u;
    // 0x141158: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x141158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x14115c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x14115cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x141160: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x141160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x141164: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x141164u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141168: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x141168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x14116c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14116cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141170: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x141170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x141174: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x141174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x141178: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x141178u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14117c: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x14117cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x141180: 0x24170001  addiu       $s7, $zero, 0x1
    ctx->pc = 0x141180u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x141184: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x141184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x141188: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x141188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x14118c: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x14118cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x141190: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x141190u;
    SET_GPR_U32(ctx, 31, 0x141198u);
    ctx->pc = 0x141194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141190u;
            // 0x141194: 0x26d50010  addiu       $s5, $s6, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 22), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141198u; }
        if (ctx->pc != 0x141198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141198u; }
        if (ctx->pc != 0x141198u) { return; }
    }
    ctx->pc = 0x141198u;
label_141198:
    // 0x141198: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141198u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x14119c: 0x24519a90  addiu       $s1, $v0, -0x6570
    ctx->pc = 0x14119cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941328));
label_1411a0:
    // 0x1411a0: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1411a0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1411a4: 0x5457001f  bnel        $v0, $s7, . + 4 + (0x1F << 2)
    ctx->pc = 0x1411A4u;
    {
        const bool branch_taken_0x1411a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 23));
        if (branch_taken_0x1411a4) {
            ctx->pc = 0x1411A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1411A4u;
            // 0x1411a8: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141224u;
            goto label_141224;
        }
    }
    ctx->pc = 0x1411ACu;
    // 0x1411ac: 0x121100  sll         $v0, $s2, 4
    ctx->pc = 0x1411acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x1411b0: 0x24140080  addiu       $s4, $zero, 0x80
    ctx->pc = 0x1411b0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1411b4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1411B4u;
    {
        const bool branch_taken_0x1411b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1411B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1411B4u;
            // 0x1411b8: 0x558021  addu        $s0, $v0, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1411b4) {
            ctx->pc = 0x1411F0u;
            goto label_1411f0;
        }
    }
    ctx->pc = 0x1411BCu;
    // 0x1411bc: 0x0  nop
    ctx->pc = 0x1411bcu;
    // NOP
label_1411c0:
    // 0x1411c0: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1411c0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1411c4: 0x9222000c  lbu         $v0, 0xC($s1)
    ctx->pc = 0x1411c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1411c8: 0x8e230010  lw          $v1, 0x10($s1)
    ctx->pc = 0x1411c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1411cc: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1411ccu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1411d0: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1411d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1411d4: 0x96220002  lhu         $v0, 0x2($s1)
    ctx->pc = 0x1411d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1411d8: 0x6ba30007  ldl         $v1, 0x7($sp)
    ctx->pc = 0x1411d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1411dc: 0x6fa30000  ldr         $v1, 0x0($sp)
    ctx->pc = 0x1411dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1411e0: 0xb203000f  sdl         $v1, 0xF($s0)
    ctx->pc = 0x1411e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1411e4: 0xb6030008  sdr         $v1, 0x8($s0)
    ctx->pc = 0x1411e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1411e8: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x1411e8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1411ec: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x1411ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
label_1411f0:
    // 0x1411f0: 0x1254000f  beq         $s2, $s4, . + 4 + (0xF << 2)
    ctx->pc = 0x1411F0u;
    {
        const bool branch_taken_0x1411f0 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 20));
        ctx->pc = 0x1411F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1411F0u;
            // 0x1411f4: 0x3c067fff  lui         $a2, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1411f0) {
            ctx->pc = 0x141230u;
            goto label_141230;
        }
    }
    ctx->pc = 0x1411F8u;
    // 0x1411f8: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x1411f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1411fc: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x1411fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x141200: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x141200u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x141204: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x141204u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x141208: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x141208u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x14120c: 0x40f809  jalr        $v0
    ctx->pc = 0x14120Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141214u);
        ctx->pc = 0x141210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14120Cu;
            // 0x141210: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141214u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140EBCu: goto label_140ebc;
            case 0x140EC4u: goto label_140ec4;
            case 0x140F08u: goto label_140f08;
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141214u; }
            if (ctx->pc != 0x141214u) { return; }
        }
        }
    }
    ctx->pc = 0x141214u;
label_141214:
    // 0x141214: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x141214u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x141218: 0x5460ffe9  bnel        $v1, $zero, . + 4 + (-0x17 << 2)
    ctx->pc = 0x141218u;
    {
        const bool branch_taken_0x141218 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x141218) {
            ctx->pc = 0x14121Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141218u;
            // 0x14121c: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1411C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1411c0;
        }
    }
    ctx->pc = 0x141220u;
    // 0x141220: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x141220u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_141224:
    // 0x141224: 0x2a620020  slti        $v0, $s3, 0x20
    ctx->pc = 0x141224u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x141228: 0x1440ffdd  bnez        $v0, . + 4 + (-0x23 << 2)
    ctx->pc = 0x141228u;
    {
        const bool branch_taken_0x141228 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14122Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141228u;
            // 0x14122c: 0x26310014  addiu       $s1, $s1, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141228) {
            ctx->pc = 0x1411A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1411a0;
        }
    }
    ctx->pc = 0x141230u;
label_141230:
    // 0x141230: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x141230u;
    SET_GPR_U32(ctx, 31, 0x141238u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141238u; }
        if (ctx->pc != 0x141238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141238u; }
        if (ctx->pc != 0x141238u) { return; }
    }
    ctx->pc = 0x141238u;
label_141238:
    // 0x141238: 0xaed20000  sw          $s2, 0x0($s6)
    ctx->pc = 0x141238u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 18));
    // 0x14123c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x14123cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141240: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x141240u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141244: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x141244u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x141248: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x141248u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x14124c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x14124cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x141250: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x141250u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x141254: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x141254u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x141258: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x141258u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x14125c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x14125cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x141260: 0x3e00008  jr          $ra
    ctx->pc = 0x141260u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141260u;
            // 0x141264: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140EBCu: goto label_140ebc;
            case 0x140EC4u: goto label_140ec4;
            case 0x140F08u: goto label_140f08;
            case 0x140F30u: goto label_140f30;
            case 0x140F50u: goto label_140f50;
            case 0x140F58u: goto label_140f58;
            case 0x140F68u: goto label_140f68;
            case 0x140F94u: goto label_140f94;
            case 0x140F98u: goto label_140f98;
            case 0x140FA4u: goto label_140fa4;
            case 0x140FF8u: goto label_140ff8;
            case 0x141000u: goto label_141000;
            case 0x141020u: goto label_141020;
            case 0x141050u: goto label_141050;
            case 0x141074u: goto label_141074;
            case 0x141084u: goto label_141084;
            case 0x141090u: goto label_141090;
            case 0x141098u: goto label_141098;
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            case 0x141198u: goto label_141198;
            case 0x1411A0u: goto label_1411a0;
            case 0x1411C0u: goto label_1411c0;
            case 0x1411F0u: goto label_1411f0;
            case 0x141214u: goto label_141214;
            case 0x141224u: goto label_141224;
            case 0x141230u: goto label_141230;
            case 0x141238u: goto label_141238;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141268u;
    // 0x141268: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141268u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14126c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x14126cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x141270: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x141270u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141274: 0x804e55a  j           func_139568
    ctx->pc = 0x141274u;
    ctx->pc = 0x141278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141274u;
            // 0x141278: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139568u;
    if (runtime->hasFunction(0x139568u)) {
        auto targetFn = runtime->lookupFunction(0x139568u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139568_0x139568(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x14127Cu;
    // 0x14127c: 0x0  nop
    ctx->pc = 0x14127cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
