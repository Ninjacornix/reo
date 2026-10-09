#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011FBB8
// Address: 0x11fbb8 - 0x1201c0
void sub_0011FBB8_0x11fbb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011FBB8_0x11fbb8");
#endif

    switch (ctx->pc) {
        case 0x11fc4cu: goto label_11fc4c;
        case 0x11fc5cu: goto label_11fc5c;
        case 0x11fc78u: goto label_11fc78;
        case 0x11fca4u: goto label_11fca4;
        case 0x11fd10u: goto label_11fd10;
        case 0x11fd3cu: goto label_11fd3c;
        case 0x11fd58u: goto label_11fd58;
        case 0x11fd70u: goto label_11fd70;
        case 0x11fd88u: goto label_11fd88;
        case 0x11fd98u: goto label_11fd98;
        case 0x11fdb0u: goto label_11fdb0;
        case 0x11fdc8u: goto label_11fdc8;
        case 0x11fddcu: goto label_11fddc;
        case 0x11fdecu: goto label_11fdec;
        case 0x11fe08u: goto label_11fe08;
        case 0x11fe18u: goto label_11fe18;
        case 0x11fe30u: goto label_11fe30;
        case 0x11fe48u: goto label_11fe48;
        case 0x11fe58u: goto label_11fe58;
        case 0x11fe68u: goto label_11fe68;
        case 0x11fe8cu: goto label_11fe8c;
        case 0x11fe9cu: goto label_11fe9c;
        case 0x11fea8u: goto label_11fea8;
        case 0x11febcu: goto label_11febc;
        case 0x11fed8u: goto label_11fed8;
        case 0x11fef0u: goto label_11fef0;
        case 0x11ff04u: goto label_11ff04;
        case 0x11ff14u: goto label_11ff14;
        case 0x11ff28u: goto label_11ff28;
        case 0x11ff38u: goto label_11ff38;
        case 0x11ff50u: goto label_11ff50;
        case 0x11ff64u: goto label_11ff64;
        case 0x11ff74u: goto label_11ff74;
        case 0x11ff88u: goto label_11ff88;
        case 0x11ff98u: goto label_11ff98;
        case 0x11ffacu: goto label_11ffac;
        case 0x11ffbcu: goto label_11ffbc;
        case 0x11ffccu: goto label_11ffcc;
        case 0x11ffecu: goto label_11ffec;
        case 0x11fffcu: goto label_11fffc;
        case 0x120018u: goto label_120018;
        case 0x120028u: goto label_120028;
        case 0x120038u: goto label_120038;
        case 0x120054u: goto label_120054;
        case 0x120068u: goto label_120068;
        case 0x120078u: goto label_120078;
        case 0x120090u: goto label_120090;
        case 0x1200a0u: goto label_1200a0;
        case 0x1200b0u: goto label_1200b0;
        case 0x1200c0u: goto label_1200c0;
        case 0x1200e8u: goto label_1200e8;
        case 0x1200f8u: goto label_1200f8;
        case 0x120108u: goto label_120108;
        case 0x120124u: goto label_120124;
        case 0x120138u: goto label_120138;
        case 0x120148u: goto label_120148;
        case 0x120160u: goto label_120160;
        case 0x120170u: goto label_120170;
        case 0x120180u: goto label_120180;
        case 0x120190u: goto label_120190;
        default: break;
    }

    ctx->pc = 0x11fbb8u;

    // 0x11fbb8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11fbb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11fbbc: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x11fbbcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fbc0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11fbc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11fbc4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x11fbc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x11fbc8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x11fbc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x11fbcc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x11fbccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x11fbd0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x11fbd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x11fbd4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x11fbd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x11fbd8: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x11fbd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x11fbdc: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x11fbdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x11fbe0: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x11fbe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x11fbe4: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x11fbe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x11fbe8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x11fbe8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fbec: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x11fbecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11fbf0: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x11fbf0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x11fbf4: 0x2983f  dsra32      $s3, $v0, 0
    ctx->pc = 0x11fbf4u;
    SET_GPR_S64(ctx, 19, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x11fbf8: 0x3c02000f  lui         $v0, 0xF
    ctx->pc = 0x11fbf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)15 << 16));
    // 0x11fbfc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11fbfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11fc00: 0x53102a  slt         $v0, $v0, $s3
    ctx->pc = 0x11fc00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x11fc04: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x11FC04u;
    {
        const bool branch_taken_0x11fc04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11FC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC04u;
            // 0x11fc08: 0xf02d  daddu       $fp, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fc04) {
            ctx->pc = 0x11FC80u;
            goto label_11fc80;
        }
    }
    ctx->pc = 0x11FC0Cu;
    // 0x11fc0c: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x11fc0cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x11fc10: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11fc10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11fc14: 0x2621024  and         $v0, $s3, $v0
    ctx->pc = 0x11fc14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
    // 0x11fc18: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x11fc18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x11fc1c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11FC1Cu;
    {
        const bool branch_taken_0x11fc1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11FC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC1Cu;
            // 0x11fc20: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fc1c) {
            ctx->pc = 0x11FC38u;
            goto label_11fc38;
        }
    }
    ctx->pc = 0x11FC24u;
    // 0x11fc24: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x11fc24u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x11fc28: 0xdc628d60  ld          $v0, -0x72A0($v1)
    ctx->pc = 0x11fc28u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 4294937952)));
    // 0x11fc2c: 0x1000015a  b           . + 4 + (0x15A << 2)
    ctx->pc = 0x11FC2Cu;
    {
        const bool branch_taken_0x11fc2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FC30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC2Cu;
            // 0x11fc30: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fc2c) {
            ctx->pc = 0x120198u;
            goto label_120198;
        }
    }
    ctx->pc = 0x11FC34u;
    // 0x11fc34: 0x0  nop
    ctx->pc = 0x11fc34u;
    // NOP
label_11fc38:
    // 0x11fc38: 0x661000b  bgez        $s3, . + 4 + (0xB << 2)
    ctx->pc = 0x11FC38u;
    {
        const bool branch_taken_0x11fc38 = (GPR_S64(ctx, 19) >= 0);
        if (branch_taken_0x11fc38) {
            ctx->pc = 0x11FC68u;
            goto label_11fc68;
        }
    }
    ctx->pc = 0x11FC40u;
    // 0x11fc40: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x11fc40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc44: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FC44u;
    SET_GPR_U32(ctx, 31, 0x11FC4Cu);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC4Cu; }
        if (ctx->pc != 0x11FC4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC4Cu; }
        if (ctx->pc != 0x11FC4Cu) { return; }
    }
    ctx->pc = 0x11FC4Cu;
label_11fc4c:
    // 0x11fc4c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11fc4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc50: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fc50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc54: 0xc04480e  jal         func_112038
    ctx->pc = 0x11FC54u;
    SET_GPR_U32(ctx, 31, 0x11FC5Cu);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC5Cu; }
        if (ctx->pc != 0x11FC5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC5Cu; }
        if (ctx->pc != 0x11FC5Cu) { return; }
    }
    ctx->pc = 0x11FC5Cu;
label_11fc5c:
    // 0x11fc5c: 0x1000014d  b           . + 4 + (0x14D << 2)
    ctx->pc = 0x11FC5Cu;
    {
        const bool branch_taken_0x11fc5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FC60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC5Cu;
            // 0x11fc60: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fc5c) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FC64u;
    // 0x11fc64: 0x0  nop
    ctx->pc = 0x11fc64u;
    // NOP
label_11fc68:
    // 0x11fc68: 0x340586a0  ori         $a1, $zero, 0x86A0
    ctx->pc = 0x11fc68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)34464);
    // 0x11fc6c: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x11fc6cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x11fc70: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FC70u;
    SET_GPR_U32(ctx, 31, 0x11FC78u);
    ctx->pc = 0x11FC74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC70u;
            // 0x11fc74: 0x241effca  addiu       $fp, $zero, -0x36 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967242));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC78u; }
        if (ctx->pc != 0x11FC78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FC78u; }
        if (ctx->pc != 0x11FC78u) { return; }
    }
    ctx->pc = 0x11FC78u;
label_11fc78:
    // 0x11fc78: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x11fc78u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc7c: 0x2983f  dsra32      $s3, $v0, 0
    ctx->pc = 0x11fc7cu;
    SET_GPR_S64(ctx, 19, GPR_S64(ctx, 2) >> (32 + 0));
label_11fc80:
    // 0x11fc80: 0x3c027fef  lui         $v0, 0x7FEF
    ctx->pc = 0x11fc80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32751 << 16));
    // 0x11fc84: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11fc84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11fc88: 0x53102a  slt         $v0, $v0, $s3
    ctx->pc = 0x11fc88u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x11fc8c: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x11FC8Cu;
    {
        const bool branch_taken_0x11fc8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fc8c) {
            ctx->pc = 0x11FC90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11FC8Cu;
            // 0x11fc90: 0x3c10000f  lui         $s0, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)15 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FCB0u;
            goto label_11fcb0;
        }
    }
    ctx->pc = 0x11FC94u;
    // 0x11fc94: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x11fc94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc98: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11fc98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fc9c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FC9Cu;
    SET_GPR_U32(ctx, 31, 0x11FCA4u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FCA4u; }
        if (ctx->pc != 0x11FCA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FCA4u; }
        if (ctx->pc != 0x11FCA4u) { return; }
    }
    ctx->pc = 0x11FCA4u;
label_11fca4:
    // 0x11fca4: 0x1000013b  b           . + 4 + (0x13B << 2)
    ctx->pc = 0x11FCA4u;
    {
        const bool branch_taken_0x11fca4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FCA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FCA4u;
            // 0x11fca8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fca4) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FCACu;
    // 0x11fcac: 0x0  nop
    ctx->pc = 0x11fcacu;
    // NOP
label_11fcb0:
    // 0x11fcb0: 0x131503  sra         $v0, $s3, 20
    ctx->pc = 0x11fcb0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 19), 20));
    // 0x11fcb4: 0x3610ffff  ori         $s0, $s0, 0xFFFF
    ctx->pc = 0x11fcb4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)65535);
    // 0x11fcb8: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x11fcb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
    // 0x11fcbc: 0x2709824  and         $s3, $s3, $s0
    ctx->pc = 0x11fcbcu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 16));
    // 0x11fcc0: 0x3c050010  lui         $a1, 0x10
    ctx->pc = 0x11fcc0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16 << 16));
    // 0x11fcc4: 0x3c040009  lui         $a0, 0x9
    ctx->pc = 0x11fcc4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)9 << 16));
    // 0x11fcc8: 0x34845f64  ori         $a0, $a0, 0x5F64
    ctx->pc = 0x11fcc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)24420);
    // 0x11fccc: 0x932021  addu        $a0, $a0, $s3
    ctx->pc = 0x11fcccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x11fcd0: 0x245efc01  addiu       $fp, $v0, -0x3FF
    ctx->pc = 0x11fcd0u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966273));
    // 0x11fcd4: 0x85b024  and         $s6, $a0, $a1
    ctx->pc = 0x11fcd4u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x11fcd8: 0x3c023ff0  lui         $v0, 0x3FF0
    ctx->pc = 0x11fcd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16368 << 16));
    // 0x11fcdc: 0x3c04ffff  lui         $a0, 0xFFFF
    ctx->pc = 0x11fcdcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65535 << 16));
    // 0x11fce0: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x11fce0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x11fce4: 0x2c21026  xor         $v0, $s6, $v0
    ctx->pc = 0x11fce4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) ^ GPR_U64(ctx, 2));
    // 0x11fce8: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x11fce8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x11fcec: 0x531025  or          $v0, $v0, $s3
    ctx->pc = 0x11fcecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 19));
    // 0x11fcf0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x11fcf0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11fcf4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x11fcf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x11fcf8: 0x163503  sra         $a2, $s6, 20
    ctx->pc = 0x11fcf8u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 22), 20));
    // 0x11fcfc: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x11fcfcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x11fd00: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x11fd00u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x11fd04: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x11fd04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd08: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FD08u;
    SET_GPR_U32(ctx, 31, 0x11FD10u);
    ctx->pc = 0x11FD0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FD08u;
            // 0x11fd0c: 0x3c6f021  addu        $fp, $fp, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD10u; }
        if (ctx->pc != 0x11FD10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD10u; }
        if (ctx->pc != 0x11FD10u) { return; }
    }
    ctx->pc = 0x11FD10u;
label_11fd10:
    // 0x11fd10: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x11fd10u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd14: 0x26620002  addiu       $v0, $s3, 0x2
    ctx->pc = 0x11fd14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x11fd18: 0x501024  and         $v0, $v0, $s0
    ctx->pc = 0x11fd18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 16));
    // 0x11fd1c: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x11fd1cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x11fd20: 0x10400055  beqz        $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x11FD20u;
    {
        const bool branch_taken_0x11fd20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fd20) {
            ctx->pc = 0x11FE78u;
            goto label_11fe78;
        }
    }
    ctx->pc = 0x11FD28u;
    // 0x11fd28: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x11fd28u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd2c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fd2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd30: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11fd30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd34: 0xc0448a6  jal         func_112298
    ctx->pc = 0x11FD34u;
    SET_GPR_U32(ctx, 31, 0x11FD3Cu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD3Cu; }
        if (ctx->pc != 0x11FD3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD3Cu; }
        if (ctx->pc != 0x11FD3Cu) { return; }
    }
    ctx->pc = 0x11FD3Cu;
label_11fd3c:
    // 0x11fd3c: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x11FD3Cu;
    {
        const bool branch_taken_0x11fd3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11fd3c) {
            ctx->pc = 0x11FDA0u;
            goto label_11fda0;
        }
    }
    ctx->pc = 0x11FD44u;
    // 0x11fd44: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11fd44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd48: 0x53c00112  beql        $fp, $zero, . + 4 + (0x112 << 2)
    ctx->pc = 0x11FD48u;
    {
        const bool branch_taken_0x11fd48 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fd48) {
            ctx->pc = 0x11FD4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11FD48u;
            // 0x11fd4c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FD50u;
    // 0x11fd50: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x11FD50u;
    SET_GPR_U32(ctx, 31, 0x11FD58u);
    ctx->pc = 0x11FD54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FD50u;
            // 0x11fd54: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD58u; }
        if (ctx->pc != 0x11FD58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD58u; }
        if (ctx->pc != 0x11FD58u) { return; }
    }
    ctx->pc = 0x11FD58u;
label_11fd58:
    // 0x11fd58: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fd58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fd5c: 0xdc258d68  ld          $a1, -0x7298($at)
    ctx->pc = 0x11fd5cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937960)));
    // 0x11fd60: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x11fd60u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd64: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11fd64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd68: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FD68u;
    SET_GPR_U32(ctx, 31, 0x11FD70u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD70u; }
        if (ctx->pc != 0x11FD70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD70u; }
        if (ctx->pc != 0x11FD70u) { return; }
    }
    ctx->pc = 0x11FD70u;
label_11fd70:
    // 0x11fd70: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11fd70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd74: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fd74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fd78: 0xdc258d70  ld          $a1, -0x7290($at)
    ctx->pc = 0x11fd78u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937968)));
    // 0x11fd7c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11fd7cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd80: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FD80u;
    SET_GPR_U32(ctx, 31, 0x11FD88u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD88u; }
        if (ctx->pc != 0x11FD88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD88u; }
        if (ctx->pc != 0x11FD88u) { return; }
    }
    ctx->pc = 0x11FD88u;
label_11fd88:
    // 0x11fd88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11fd88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd8c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fd8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fd90: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FD90u;
    SET_GPR_U32(ctx, 31, 0x11FD98u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD98u; }
        if (ctx->pc != 0x11FD98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FD98u; }
        if (ctx->pc != 0x11FD98u) { return; }
    }
    ctx->pc = 0x11FD98u;
label_11fd98:
    // 0x11fd98: 0x100000fe  b           . + 4 + (0xFE << 2)
    ctx->pc = 0x11FD98u;
    {
        const bool branch_taken_0x11fd98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FD9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FD98u;
            // 0x11fd9c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fd98) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FDA0u;
label_11fda0:
    // 0x11fda0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x11fda0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fda4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fda4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fda8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FDA8u;
    SET_GPR_U32(ctx, 31, 0x11FDB0u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDB0u; }
        if (ctx->pc != 0x11FDB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDB0u; }
        if (ctx->pc != 0x11FDB0u) { return; }
    }
    ctx->pc = 0x11FDB0u;
label_11fdb0:
    // 0x11fdb0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fdb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdb4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fdb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fdb8: 0xdc258d78  ld          $a1, -0x7288($at)
    ctx->pc = 0x11fdb8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937976)));
    // 0x11fdbc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11fdbcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdc0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FDC0u;
    SET_GPR_U32(ctx, 31, 0x11FDC8u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDC8u; }
        if (ctx->pc != 0x11FDC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDC8u; }
        if (ctx->pc != 0x11FDC8u) { return; }
    }
    ctx->pc = 0x11FDC8u;
label_11fdc8:
    // 0x11fdc8: 0x3404ff80  ori         $a0, $zero, 0xFF80
    ctx->pc = 0x11fdc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x11fdcc: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x11fdccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x11fdd0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fdd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdd4: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FDD4u;
    SET_GPR_U32(ctx, 31, 0x11FDDCu);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDDCu; }
        if (ctx->pc != 0x11FDDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDDCu; }
        if (ctx->pc != 0x11FDDCu) { return; }
    }
    ctx->pc = 0x11FDDCu;
label_11fddc:
    // 0x11fddc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11fddcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fde0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fde0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fde4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FDE4u;
    SET_GPR_U32(ctx, 31, 0x11FDECu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDECu; }
        if (ctx->pc != 0x11FDECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FDECu; }
        if (ctx->pc != 0x11FDECu) { return; }
    }
    ctx->pc = 0x11FDECu;
label_11fdec:
    // 0x11fdec: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11fdecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdf0: 0x17c00007  bnez        $fp, . + 4 + (0x7 << 2)
    ctx->pc = 0x11FDF0u;
    {
        const bool branch_taken_0x11fdf0 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x11fdf0) {
            ctx->pc = 0x11FE10u;
            goto label_11fe10;
        }
    }
    ctx->pc = 0x11FDF8u;
    // 0x11fdf8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fdf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fdfc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x11fdfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe00: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FE00u;
    SET_GPR_U32(ctx, 31, 0x11FE08u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE08u; }
        if (ctx->pc != 0x11FE08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE08u; }
        if (ctx->pc != 0x11FE08u) { return; }
    }
    ctx->pc = 0x11FE08u;
label_11fe08:
    // 0x11fe08: 0x100000e2  b           . + 4 + (0xE2 << 2)
    ctx->pc = 0x11FE08u;
    {
        const bool branch_taken_0x11fe08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FE08u;
            // 0x11fe0c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fe08) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x11FE10u;
label_11fe10:
    // 0x11fe10: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x11FE10u;
    SET_GPR_U32(ctx, 31, 0x11FE18u);
    ctx->pc = 0x11FE14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FE10u;
            // 0x11fe14: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE18u; }
        if (ctx->pc != 0x11FE18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE18u; }
        if (ctx->pc != 0x11FE18u) { return; }
    }
    ctx->pc = 0x11FE18u;
label_11fe18:
    // 0x11fe18: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fe18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fe1c: 0xdc258d80  ld          $a1, -0x7280($at)
    ctx->pc = 0x11fe1cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937984)));
    // 0x11fe20: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x11fe20u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe24: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11fe24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe28: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FE28u;
    SET_GPR_U32(ctx, 31, 0x11FE30u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE30u; }
        if (ctx->pc != 0x11FE30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE30u; }
        if (ctx->pc != 0x11FE30u) { return; }
    }
    ctx->pc = 0x11FE30u;
label_11fe30:
    // 0x11fe30: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11fe30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe34: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fe34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fe38: 0xdc258d88  ld          $a1, -0x7278($at)
    ctx->pc = 0x11fe38u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937992)));
    // 0x11fe3c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11fe3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe40: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FE40u;
    SET_GPR_U32(ctx, 31, 0x11FE48u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE48u; }
        if (ctx->pc != 0x11FE48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE48u; }
        if (ctx->pc != 0x11FE48u) { return; }
    }
    ctx->pc = 0x11FE48u;
label_11fe48:
    // 0x11fe48: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x11fe48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe4c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fe4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe50: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FE50u;
    SET_GPR_U32(ctx, 31, 0x11FE58u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE58u; }
        if (ctx->pc != 0x11FE58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE58u; }
        if (ctx->pc != 0x11FE58u) { return; }
    }
    ctx->pc = 0x11FE58u;
label_11fe58:
    // 0x11fe58: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x11fe58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe5c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fe5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe60: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FE60u;
    SET_GPR_U32(ctx, 31, 0x11FE68u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE68u; }
        if (ctx->pc != 0x11FE68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE68u; }
        if (ctx->pc != 0x11FE68u) { return; }
    }
    ctx->pc = 0x11FE68u;
label_11fe68:
    // 0x11fe68: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11fe68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe6c: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x11FE6Cu;
    {
        const bool branch_taken_0x11fe6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fe6c) {
            ctx->pc = 0x1200FCu;
            goto label_1200fc;
        }
    }
    ctx->pc = 0x11FE74u;
    // 0x11fe74: 0x0  nop
    ctx->pc = 0x11fe74u;
    // NOP
label_11fe78:
    // 0x11fe78: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x11fe78u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x11fe7c: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x11fe7cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x11fe80: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fe80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe84: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FE84u;
    SET_GPR_U32(ctx, 31, 0x11FE8Cu);
    ctx->pc = 0x11FE88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FE84u;
            // 0x11fe88: 0x3c100006  lui         $s0, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)6 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE8Cu; }
        if (ctx->pc != 0x11FE8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE8Cu; }
        if (ctx->pc != 0x11FE8Cu) { return; }
    }
    ctx->pc = 0x11FE8Cu;
label_11fe8c:
    // 0x11fe8c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11fe8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe90: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fe90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fe94: 0xc04480e  jal         func_112038
    ctx->pc = 0x11FE94u;
    SET_GPR_U32(ctx, 31, 0x11FE9Cu);
    ctx->pc = 0x11FE98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FE94u;
            // 0x11fe98: 0x3610b851  ori         $s0, $s0, 0xB851 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)47185);
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE9Cu; }
        if (ctx->pc != 0x11FE9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FE9Cu; }
        if (ctx->pc != 0x11FE9Cu) { return; }
    }
    ctx->pc = 0x11FE9Cu;
label_11fe9c:
    // 0x11fe9c: 0x40b82d  daddu       $s7, $v0, $zero
    ctx->pc = 0x11fe9cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fea0: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x11FEA0u;
    SET_GPR_U32(ctx, 31, 0x11FEA8u);
    ctx->pc = 0x11FEA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FEA0u;
            // 0x11fea4: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEA8u; }
        if (ctx->pc != 0x11FEA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEA8u; }
        if (ctx->pc != 0x11FEA8u) { return; }
    }
    ctx->pc = 0x11FEA8u;
label_11fea8:
    // 0x11fea8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x11fea8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11feac: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x11feacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11feb0: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x11feb0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11feb4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FEB4u;
    SET_GPR_U32(ctx, 31, 0x11FEBCu);
    ctx->pc = 0x11FEB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FEB4u;
            // 0x11feb8: 0x2138023  subu        $s0, $s0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEBCu; }
        if (ctx->pc != 0x11FEBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEBCu; }
        if (ctx->pc != 0x11FEBCu) { return; }
    }
    ctx->pc = 0x11FEBCu;
label_11febc:
    // 0x11febc: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11febcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fec0: 0x3c02fff9  lui         $v0, 0xFFF9
    ctx->pc = 0x11fec0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65529 << 16));
    // 0x11fec4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x11fec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fec8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x11fec8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fecc: 0x3442eb86  ori         $v0, $v0, 0xEB86
    ctx->pc = 0x11feccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)60294);
    // 0x11fed0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FED0u;
    SET_GPR_U32(ctx, 31, 0x11FED8u);
    ctx->pc = 0x11FED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FED0u;
            // 0x11fed4: 0x262b021  addu        $s6, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FED8u; }
        if (ctx->pc != 0x11FED8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FED8u; }
        if (ctx->pc != 0x11FED8u) { return; }
    }
    ctx->pc = 0x11FED8u;
label_11fed8:
    // 0x11fed8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11fed8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fedc: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fedcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fee0: 0xdc258d90  ld          $a1, -0x7270($at)
    ctx->pc = 0x11fee0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938000)));
    // 0x11fee4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11fee4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fee8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FEE8u;
    SET_GPR_U32(ctx, 31, 0x11FEF0u);
    ctx->pc = 0x11FEECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11FEE8u;
            // 0x11feec: 0x2d0b025  or          $s6, $s6, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEF0u; }
        if (ctx->pc != 0x11FEF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FEF0u; }
        if (ctx->pc != 0x11FEF0u) { return; }
    }
    ctx->pc = 0x11FEF0u;
label_11fef0:
    // 0x11fef0: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fef0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fef4: 0xdc258d98  ld          $a1, -0x7268($at)
    ctx->pc = 0x11fef4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938008)));
    // 0x11fef8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fef8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fefc: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FEFCu;
    SET_GPR_U32(ctx, 31, 0x11FF04u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF04u; }
        if (ctx->pc != 0x11FF04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF04u; }
        if (ctx->pc != 0x11FF04u) { return; }
    }
    ctx->pc = 0x11FF04u;
label_11ff04:
    // 0x11ff04: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff08: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ff08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff0c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF0Cu;
    SET_GPR_U32(ctx, 31, 0x11FF14u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF14u; }
        if (ctx->pc != 0x11FF14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF14u; }
        if (ctx->pc != 0x11FF14u) { return; }
    }
    ctx->pc = 0x11FF14u;
label_11ff14:
    // 0x11ff14: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff18: 0xdc258da0  ld          $a1, -0x7260($at)
    ctx->pc = 0x11ff18u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938016)));
    // 0x11ff1c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ff1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff20: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FF20u;
    SET_GPR_U32(ctx, 31, 0x11FF28u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF28u; }
        if (ctx->pc != 0x11FF28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF28u; }
        if (ctx->pc != 0x11FF28u) { return; }
    }
    ctx->pc = 0x11FF28u;
label_11ff28:
    // 0x11ff28: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff2c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ff2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff30: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF30u;
    SET_GPR_U32(ctx, 31, 0x11FF38u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF38u; }
        if (ctx->pc != 0x11FF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF38u; }
        if (ctx->pc != 0x11FF38u) { return; }
    }
    ctx->pc = 0x11FF38u;
label_11ff38:
    // 0x11ff38: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff3c: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff40: 0xdc258da8  ld          $a1, -0x7258($at)
    ctx->pc = 0x11ff40u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938024)));
    // 0x11ff44: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x11ff44u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff48: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF48u;
    SET_GPR_U32(ctx, 31, 0x11FF50u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF50u; }
        if (ctx->pc != 0x11FF50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF50u; }
        if (ctx->pc != 0x11FF50u) { return; }
    }
    ctx->pc = 0x11FF50u;
label_11ff50:
    // 0x11ff50: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff54: 0xdc258db0  ld          $a1, -0x7250($at)
    ctx->pc = 0x11ff54u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938032)));
    // 0x11ff58: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ff58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff5c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FF5Cu;
    SET_GPR_U32(ctx, 31, 0x11FF64u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF64u; }
        if (ctx->pc != 0x11FF64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF64u; }
        if (ctx->pc != 0x11FF64u) { return; }
    }
    ctx->pc = 0x11FF64u;
label_11ff64:
    // 0x11ff64: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff68: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ff68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff6c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF6Cu;
    SET_GPR_U32(ctx, 31, 0x11FF74u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF74u; }
        if (ctx->pc != 0x11FF74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF74u; }
        if (ctx->pc != 0x11FF74u) { return; }
    }
    ctx->pc = 0x11FF74u;
label_11ff74:
    // 0x11ff74: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff78: 0xdc258db8  ld          $a1, -0x7248($at)
    ctx->pc = 0x11ff78u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938040)));
    // 0x11ff7c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ff7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff80: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FF80u;
    SET_GPR_U32(ctx, 31, 0x11FF88u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF88u; }
        if (ctx->pc != 0x11FF88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF88u; }
        if (ctx->pc != 0x11FF88u) { return; }
    }
    ctx->pc = 0x11FF88u;
label_11ff88:
    // 0x11ff88: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11ff88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff8c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ff8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ff90: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FF90u;
    SET_GPR_U32(ctx, 31, 0x11FF98u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF98u; }
        if (ctx->pc != 0x11FF98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FF98u; }
        if (ctx->pc != 0x11FF98u) { return; }
    }
    ctx->pc = 0x11FF98u;
label_11ff98:
    // 0x11ff98: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11ff98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11ff9c: 0xdc258dc0  ld          $a1, -0x7240($at)
    ctx->pc = 0x11ff9cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938048)));
    // 0x11ffa0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ffa0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffa4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FFA4u;
    SET_GPR_U32(ctx, 31, 0x11FFACu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFACu; }
        if (ctx->pc != 0x11FFACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFACu; }
        if (ctx->pc != 0x11FFACu) { return; }
    }
    ctx->pc = 0x11FFACu;
label_11ffac:
    // 0x11ffac: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x11ffacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffb0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11ffb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffb4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FFB4u;
    SET_GPR_U32(ctx, 31, 0x11FFBCu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFBCu; }
        if (ctx->pc != 0x11FFBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFBCu; }
        if (ctx->pc != 0x11FFBCu) { return; }
    }
    ctx->pc = 0x11FFBCu;
label_11ffbc:
    // 0x11ffbc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11ffbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffc0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11ffc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffc4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11FFC4u;
    SET_GPR_U32(ctx, 31, 0x11FFCCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFCCu; }
        if (ctx->pc != 0x11FFCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFCCu; }
        if (ctx->pc != 0x11FFCCu) { return; }
    }
    ctx->pc = 0x11FFCCu;
label_11ffcc:
    // 0x11ffcc: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11ffccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffd0: 0x1ac0003f  blez        $s6, . + 4 + (0x3F << 2)
    ctx->pc = 0x11FFD0u;
    {
        const bool branch_taken_0x11ffd0 = (GPR_S64(ctx, 22) <= 0);
        if (branch_taken_0x11ffd0) {
            ctx->pc = 0x1200D0u;
            goto label_1200d0;
        }
    }
    ctx->pc = 0x11FFD8u;
    // 0x11ffd8: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x11ffd8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x11ffdc: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x11ffdcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x11ffe0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x11ffe0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ffe4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FFE4u;
    SET_GPR_U32(ctx, 31, 0x11FFECu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFECu; }
        if (ctx->pc != 0x11FFECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFECu; }
        if (ctx->pc != 0x11FFECu) { return; }
    }
    ctx->pc = 0x11FFECu;
label_11ffec:
    // 0x11ffec: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x11ffecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fff0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fff4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11FFF4u;
    SET_GPR_U32(ctx, 31, 0x11FFFCu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFFCu; }
        if (ctx->pc != 0x11FFFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FFFCu; }
        if (ctx->pc != 0x11FFFCu) { return; }
    }
    ctx->pc = 0x11FFFCu;
label_11fffc:
    // 0x11fffc: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x11fffcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120000: 0x17c0000f  bnez        $fp, . + 4 + (0xF << 2)
    ctx->pc = 0x120000u;
    {
        const bool branch_taken_0x120000 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x120000) {
            ctx->pc = 0x120040u;
            goto label_120040;
        }
    }
    ctx->pc = 0x120008u;
    // 0x120008: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x120008u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12000c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x12000cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120010: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x120010u;
    SET_GPR_U32(ctx, 31, 0x120018u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120018u; }
        if (ctx->pc != 0x120018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120018u; }
        if (ctx->pc != 0x120018u) { return; }
    }
    ctx->pc = 0x120018u;
label_120018:
    // 0x120018: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x120018u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12001c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12001cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120020: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120020u;
    SET_GPR_U32(ctx, 31, 0x120028u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120028u; }
        if (ctx->pc != 0x120028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120028u; }
        if (ctx->pc != 0x120028u) { return; }
    }
    ctx->pc = 0x120028u;
label_120028:
    // 0x120028: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x120028u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12002c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12002cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120030: 0xc044752  jal         func_111D48
    ctx->pc = 0x120030u;
    SET_GPR_U32(ctx, 31, 0x120038u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120038u; }
        if (ctx->pc != 0x120038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120038u; }
        if (ctx->pc != 0x120038u) { return; }
    }
    ctx->pc = 0x120038u;
label_120038:
    // 0x120038: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x120038u;
    {
        const bool branch_taken_0x120038 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x120038) {
            ctx->pc = 0x1200F8u;
            goto label_1200f8;
        }
    }
    ctx->pc = 0x120040u;
label_120040:
    // 0x120040: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x120040u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x120044: 0xdc258dc8  ld          $a1, -0x7238($at)
    ctx->pc = 0x120044u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938056)));
    // 0x120048: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x120048u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12004c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x12004Cu;
    SET_GPR_U32(ctx, 31, 0x120054u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120054u; }
        if (ctx->pc != 0x120054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120054u; }
        if (ctx->pc != 0x120054u) { return; }
    }
    ctx->pc = 0x120054u;
label_120054:
    // 0x120054: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x120054u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120058: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x120058u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12005c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12005cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120060: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x120060u;
    SET_GPR_U32(ctx, 31, 0x120068u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120068u; }
        if (ctx->pc != 0x120068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120068u; }
        if (ctx->pc != 0x120068u) { return; }
    }
    ctx->pc = 0x120068u;
label_120068:
    // 0x120068: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x120068u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12006c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12006cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120070: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120070u;
    SET_GPR_U32(ctx, 31, 0x120078u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120078u; }
        if (ctx->pc != 0x120078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120078u; }
        if (ctx->pc != 0x120078u) { return; }
    }
    ctx->pc = 0x120078u;
label_120078:
    // 0x120078: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x120078u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12007c: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x12007cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x120080: 0xdc258dd0  ld          $a1, -0x7230($at)
    ctx->pc = 0x120080u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938064)));
    // 0x120084: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x120084u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120088: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120088u;
    SET_GPR_U32(ctx, 31, 0x120090u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120090u; }
        if (ctx->pc != 0x120090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120090u; }
        if (ctx->pc != 0x120090u) { return; }
    }
    ctx->pc = 0x120090u;
label_120090:
    // 0x120090: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x120090u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120094: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x120094u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120098: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x120098u;
    SET_GPR_U32(ctx, 31, 0x1200A0u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200A0u; }
        if (ctx->pc != 0x1200A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200A0u; }
        if (ctx->pc != 0x1200A0u) { return; }
    }
    ctx->pc = 0x1200A0u;
label_1200a0:
    // 0x1200a0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1200a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200a4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1200a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200a8: 0xc044752  jal         func_111D48
    ctx->pc = 0x1200A8u;
    SET_GPR_U32(ctx, 31, 0x1200B0u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200B0u; }
        if (ctx->pc != 0x1200B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200B0u; }
        if (ctx->pc != 0x1200B0u) { return; }
    }
    ctx->pc = 0x1200B0u;
label_1200b0:
    // 0x1200b0: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1200b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200b4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1200b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200b8: 0xc044752  jal         func_111D48
    ctx->pc = 0x1200B8u;
    SET_GPR_U32(ctx, 31, 0x1200C0u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200C0u; }
        if (ctx->pc != 0x1200C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200C0u; }
        if (ctx->pc != 0x1200C0u) { return; }
    }
    ctx->pc = 0x1200C0u;
label_1200c0:
    // 0x1200c0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1200c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200c4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1200C4u;
    {
        const bool branch_taken_0x1200c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1200c4) {
            ctx->pc = 0x1200FCu;
            goto label_1200fc;
        }
    }
    ctx->pc = 0x1200CCu;
    // 0x1200cc: 0x0  nop
    ctx->pc = 0x1200ccu;
    // NOP
label_1200d0:
    // 0x1200d0: 0x17c0000f  bnez        $fp, . + 4 + (0xF << 2)
    ctx->pc = 0x1200D0u;
    {
        const bool branch_taken_0x1200d0 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0x1200d0) {
            ctx->pc = 0x120110u;
            goto label_120110;
        }
    }
    ctx->pc = 0x1200D8u;
    // 0x1200d8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1200d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200dc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1200dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200e0: 0xc044752  jal         func_111D48
    ctx->pc = 0x1200E0u;
    SET_GPR_U32(ctx, 31, 0x1200E8u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200E8u; }
        if (ctx->pc != 0x1200E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200E8u; }
        if (ctx->pc != 0x1200E8u) { return; }
    }
    ctx->pc = 0x1200E8u;
label_1200e8:
    // 0x1200e8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1200e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200ec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1200ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1200f0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1200F0u;
    SET_GPR_U32(ctx, 31, 0x1200F8u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200F8u; }
        if (ctx->pc != 0x1200F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1200F8u; }
        if (ctx->pc != 0x1200F8u) { return; }
    }
    ctx->pc = 0x1200F8u;
label_1200f8:
    // 0x1200f8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1200f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_1200fc:
    // 0x1200fc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1200fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120100: 0xc044752  jal         func_111D48
    ctx->pc = 0x120100u;
    SET_GPR_U32(ctx, 31, 0x120108u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120108u; }
        if (ctx->pc != 0x120108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120108u; }
        if (ctx->pc != 0x120108u) { return; }
    }
    ctx->pc = 0x120108u;
label_120108:
    // 0x120108: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x120108u;
    {
        const bool branch_taken_0x120108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12010Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120108u;
            // 0x12010c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120108) {
            ctx->pc = 0x120194u;
            goto label_120194;
        }
    }
    ctx->pc = 0x120110u;
label_120110:
    // 0x120110: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x120110u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x120114: 0xdc258dd8  ld          $a1, -0x7228($at)
    ctx->pc = 0x120114u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938072)));
    // 0x120118: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x120118u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12011c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x12011Cu;
    SET_GPR_U32(ctx, 31, 0x120124u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120124u; }
        if (ctx->pc != 0x120124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120124u; }
        if (ctx->pc != 0x120124u) { return; }
    }
    ctx->pc = 0x120124u;
label_120124:
    // 0x120124: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x120124u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120128: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x120128u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12012c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x12012cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120130: 0xc044752  jal         func_111D48
    ctx->pc = 0x120130u;
    SET_GPR_U32(ctx, 31, 0x120138u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120138u; }
        if (ctx->pc != 0x120138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120138u; }
        if (ctx->pc != 0x120138u) { return; }
    }
    ctx->pc = 0x120138u;
label_120138:
    // 0x120138: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x120138u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12013c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12013cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120140: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120140u;
    SET_GPR_U32(ctx, 31, 0x120148u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120148u; }
        if (ctx->pc != 0x120148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120148u; }
        if (ctx->pc != 0x120148u) { return; }
    }
    ctx->pc = 0x120148u;
label_120148:
    // 0x120148: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x120148u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12014c: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x12014cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x120150: 0xdc258de0  ld          $a1, -0x7220($at)
    ctx->pc = 0x120150u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294938080)));
    // 0x120154: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x120154u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120158: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x120158u;
    SET_GPR_U32(ctx, 31, 0x120160u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120160u; }
        if (ctx->pc != 0x120160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120160u; }
        if (ctx->pc != 0x120160u) { return; }
    }
    ctx->pc = 0x120160u;
label_120160:
    // 0x120160: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x120160u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120164: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x120164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120168: 0xc044752  jal         func_111D48
    ctx->pc = 0x120168u;
    SET_GPR_U32(ctx, 31, 0x120170u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120170u; }
        if (ctx->pc != 0x120170u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120170u; }
        if (ctx->pc != 0x120170u) { return; }
    }
    ctx->pc = 0x120170u;
label_120170:
    // 0x120170: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x120170u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120174: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x120174u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120178: 0xc044752  jal         func_111D48
    ctx->pc = 0x120178u;
    SET_GPR_U32(ctx, 31, 0x120180u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120180u; }
        if (ctx->pc != 0x120180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120180u; }
        if (ctx->pc != 0x120180u) { return; }
    }
    ctx->pc = 0x120180u;
label_120180:
    // 0x120180: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x120180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120184: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x120184u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120188: 0xc044752  jal         func_111D48
    ctx->pc = 0x120188u;
    SET_GPR_U32(ctx, 31, 0x120190u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120190u; }
        if (ctx->pc != 0x120190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120190u; }
        if (ctx->pc != 0x120190u) { return; }
    }
    ctx->pc = 0x120190u;
label_120190:
    // 0x120190: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x120190u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_120194:
    // 0x120194: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x120194u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_120198:
    // 0x120198: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x120198u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12019c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12019cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1201a0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1201a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1201a4: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1201a4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1201a8: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1201a8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1201ac: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x1201acu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1201b0: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1201b0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1201b4: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1201b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1201b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1201B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1201BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1201B8u;
            // 0x1201bc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11FC38u: goto label_11fc38;
            case 0x11FC4Cu: goto label_11fc4c;
            case 0x11FC5Cu: goto label_11fc5c;
            case 0x11FC68u: goto label_11fc68;
            case 0x11FC78u: goto label_11fc78;
            case 0x11FC80u: goto label_11fc80;
            case 0x11FCA4u: goto label_11fca4;
            case 0x11FCB0u: goto label_11fcb0;
            case 0x11FD10u: goto label_11fd10;
            case 0x11FD3Cu: goto label_11fd3c;
            case 0x11FD58u: goto label_11fd58;
            case 0x11FD70u: goto label_11fd70;
            case 0x11FD88u: goto label_11fd88;
            case 0x11FD98u: goto label_11fd98;
            case 0x11FDA0u: goto label_11fda0;
            case 0x11FDB0u: goto label_11fdb0;
            case 0x11FDC8u: goto label_11fdc8;
            case 0x11FDDCu: goto label_11fddc;
            case 0x11FDECu: goto label_11fdec;
            case 0x11FE08u: goto label_11fe08;
            case 0x11FE10u: goto label_11fe10;
            case 0x11FE18u: goto label_11fe18;
            case 0x11FE30u: goto label_11fe30;
            case 0x11FE48u: goto label_11fe48;
            case 0x11FE58u: goto label_11fe58;
            case 0x11FE68u: goto label_11fe68;
            case 0x11FE78u: goto label_11fe78;
            case 0x11FE8Cu: goto label_11fe8c;
            case 0x11FE9Cu: goto label_11fe9c;
            case 0x11FEA8u: goto label_11fea8;
            case 0x11FEBCu: goto label_11febc;
            case 0x11FED8u: goto label_11fed8;
            case 0x11FEF0u: goto label_11fef0;
            case 0x11FF04u: goto label_11ff04;
            case 0x11FF14u: goto label_11ff14;
            case 0x11FF28u: goto label_11ff28;
            case 0x11FF38u: goto label_11ff38;
            case 0x11FF50u: goto label_11ff50;
            case 0x11FF64u: goto label_11ff64;
            case 0x11FF74u: goto label_11ff74;
            case 0x11FF88u: goto label_11ff88;
            case 0x11FF98u: goto label_11ff98;
            case 0x11FFACu: goto label_11ffac;
            case 0x11FFBCu: goto label_11ffbc;
            case 0x11FFCCu: goto label_11ffcc;
            case 0x11FFECu: goto label_11ffec;
            case 0x11FFFCu: goto label_11fffc;
            case 0x120018u: goto label_120018;
            case 0x120028u: goto label_120028;
            case 0x120038u: goto label_120038;
            case 0x120040u: goto label_120040;
            case 0x120054u: goto label_120054;
            case 0x120068u: goto label_120068;
            case 0x120078u: goto label_120078;
            case 0x120090u: goto label_120090;
            case 0x1200A0u: goto label_1200a0;
            case 0x1200B0u: goto label_1200b0;
            case 0x1200C0u: goto label_1200c0;
            case 0x1200D0u: goto label_1200d0;
            case 0x1200E8u: goto label_1200e8;
            case 0x1200F8u: goto label_1200f8;
            case 0x1200FCu: goto label_1200fc;
            case 0x120108u: goto label_120108;
            case 0x120110u: goto label_120110;
            case 0x120124u: goto label_120124;
            case 0x120138u: goto label_120138;
            case 0x120148u: goto label_120148;
            case 0x120160u: goto label_120160;
            case 0x120170u: goto label_120170;
            case 0x120180u: goto label_120180;
            case 0x120190u: goto label_120190;
            case 0x120194u: goto label_120194;
            case 0x120198u: goto label_120198;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1201C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
