#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00120AE8
// Address: 0x120ae8 - 0x120e98
void sub_00120AE8_0x120ae8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00120AE8_0x120ae8");
#endif

    switch (ctx->pc) {
        case 0x120c48u: goto label_120c48;
        case 0x120de0u: goto label_120de0;
        case 0x120e28u: goto label_120e28;
        case 0x120e5cu: goto label_120e5c;
        default: break;
    }

    ctx->pc = 0x120ae8u;

    // 0x120ae8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x120ae8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x120aec: 0x46006046  mov.s       $f1, $f12
    ctx->pc = 0x120aecu;
    ctx->f[1] = FPU_MOV_S(ctx->f[12]);
    // 0x120af0: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x120af0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x120af4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x120af4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120af8: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x120af8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x120afc: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x120afcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x120b00: 0x44120800  mfc1        $s2, $f1
    ctx->pc = 0x120b00u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 18, bits); }
    // 0x120b04: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x120b04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x120b08: 0x3c023f49  lui         $v0, 0x3F49
    ctx->pc = 0x120b08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16201 << 16));
    // 0x120b0c: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x120b0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x120b10: 0x34420fd8  ori         $v0, $v0, 0xFD8
    ctx->pc = 0x120b10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4056);
    // 0x120b14: 0x2438024  and         $s0, $s2, $v1
    ctx->pc = 0x120b14u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 18) & GPR_U64(ctx, 3));
    // 0x120b18: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x120b18u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x120b1c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x120B1Cu;
    {
        const bool branch_taken_0x120b1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x120B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120B1Cu;
            // 0x120b20: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120b1c) {
            ctx->pc = 0x120B38u;
            goto label_120b38;
        }
    }
    ctx->pc = 0x120B24u;
    // 0x120b24: 0xe6210000  swc1        $f1, 0x0($s1)
    ctx->pc = 0x120b24u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x120b28: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x120b28u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120b2c: 0x100000d4  b           . + 4 + (0xD4 << 2)
    ctx->pc = 0x120B2Cu;
    {
        const bool branch_taken_0x120b2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120B2Cu;
            // 0x120b30: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120b2c) {
            ctx->pc = 0x120E80u;
            goto label_120e80;
        }
    }
    ctx->pc = 0x120B34u;
    // 0x120b34: 0x0  nop
    ctx->pc = 0x120b34u;
    // NOP
label_120b38:
    // 0x120b38: 0x3c024016  lui         $v0, 0x4016
    ctx->pc = 0x120b38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16406 << 16));
    // 0x120b3c: 0x3442cbe3  ori         $v0, $v0, 0xCBE3
    ctx->pc = 0x120b3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)52195);
    // 0x120b40: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x120b40u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x120b44: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x120B44u;
    {
        const bool branch_taken_0x120b44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x120B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120B44u;
            // 0x120b48: 0x3c024349  lui         $v0, 0x4349 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17225 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120b44) {
            ctx->pc = 0x120C30u;
            goto label_120c30;
        }
    }
    ctx->pc = 0x120B4Cu;
    // 0x120b4c: 0x1a40001c  blez        $s2, . + 4 + (0x1C << 2)
    ctx->pc = 0x120B4Cu;
    {
        const bool branch_taken_0x120b4c = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x120B50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120B4Cu;
            // 0x120b50: 0x2403fff0  addiu       $v1, $zero, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120b4c) {
            ctx->pc = 0x120BC0u;
            goto label_120bc0;
        }
    }
    ctx->pc = 0x120B54u;
    // 0x120b54: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x120b54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x120b58: 0x34210f80  ori         $at, $at, 0xF80
    ctx->pc = 0x120b58u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)3968);
    // 0x120b5c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120b5cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120b60: 0x3c023fc9  lui         $v0, 0x3FC9
    ctx->pc = 0x120b60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16329 << 16));
    // 0x120b64: 0x2031824  and         $v1, $s0, $v1
    ctx->pc = 0x120b64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x120b68: 0x34420fd0  ori         $v0, $v0, 0xFD0
    ctx->pc = 0x120b68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4048);
    // 0x120b6c: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x120B6Cu;
    {
        const bool branch_taken_0x120b6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x120B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120B6Cu;
            // 0x120b70: 0x46000b01  sub.s       $f12, $f1, $f0 (Delay Slot)
        ctx->f[12] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120b6c) {
            ctx->pc = 0x120B88u;
            goto label_120b88;
        }
    }
    ctx->pc = 0x120B74u;
    // 0x120b74: 0x3c013735  lui         $at, 0x3735
    ctx->pc = 0x120b74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14133 << 16));
    // 0x120b78: 0x34214442  ori         $at, $at, 0x4442
    ctx->pc = 0x120b78u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)17474);
    // 0x120b7c: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x120b7cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120b80: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x120B80u;
    {
        const bool branch_taken_0x120b80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120B84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120B80u;
            // 0x120b84: 0x46026041  sub.s       $f1, $f12, $f2 (Delay Slot)
        ctx->f[1] = FPU_SUB_S(ctx->f[12], ctx->f[2]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120b80) {
            ctx->pc = 0x120BA8u;
            goto label_120ba8;
        }
    }
    ctx->pc = 0x120B88u;
label_120b88:
    // 0x120b88: 0x3c013735  lui         $at, 0x3735
    ctx->pc = 0x120b88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14133 << 16));
    // 0x120b8c: 0x342143ff  ori         $at, $at, 0x43FF
    ctx->pc = 0x120b8cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)17407);
    // 0x120b90: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120b90u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120b94: 0x3c012e85  lui         $at, 0x2E85
    ctx->pc = 0x120b94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)11909 << 16));
    // 0x120b98: 0x3421a308  ori         $at, $at, 0xA308
    ctx->pc = 0x120b98u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)41736);
    // 0x120b9c: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x120b9cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120ba0: 0x46006301  sub.s       $f12, $f12, $f0
    ctx->pc = 0x120ba0u;
    ctx->f[12] = FPU_SUB_S(ctx->f[12], ctx->f[0]);
    // 0x120ba4: 0x46026041  sub.s       $f1, $f12, $f2
    ctx->pc = 0x120ba4u;
    ctx->f[1] = FPU_SUB_S(ctx->f[12], ctx->f[2]);
label_120ba8:
    // 0x120ba8: 0x46016001  sub.s       $f0, $f12, $f1
    ctx->pc = 0x120ba8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[12], ctx->f[1]);
    // 0x120bac: 0xe6210000  swc1        $f1, 0x0($s1)
    ctx->pc = 0x120bacu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x120bb0: 0x46020001  sub.s       $f0, $f0, $f2
    ctx->pc = 0x120bb0u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[2]);
    // 0x120bb4: 0xe6200004  swc1        $f0, 0x4($s1)
    ctx->pc = 0x120bb4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 4), bits); }
    // 0x120bb8: 0x100000b1  b           . + 4 + (0xB1 << 2)
    ctx->pc = 0x120BB8u;
    {
        const bool branch_taken_0x120bb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120BB8u;
            // 0x120bbc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120bb8) {
            ctx->pc = 0x120E80u;
            goto label_120e80;
        }
    }
    ctx->pc = 0x120BC0u;
label_120bc0:
    // 0x120bc0: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x120bc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x120bc4: 0x34210f80  ori         $at, $at, 0xF80
    ctx->pc = 0x120bc4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)3968);
    // 0x120bc8: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120bc8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120bcc: 0x3c023fc9  lui         $v0, 0x3FC9
    ctx->pc = 0x120bccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16329 << 16));
    // 0x120bd0: 0x2031824  and         $v1, $s0, $v1
    ctx->pc = 0x120bd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x120bd4: 0x34420fd0  ori         $v0, $v0, 0xFD0
    ctx->pc = 0x120bd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4048);
    // 0x120bd8: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x120BD8u;
    {
        const bool branch_taken_0x120bd8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x120BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120BD8u;
            // 0x120bdc: 0x46000b00  add.s       $f12, $f1, $f0 (Delay Slot)
        ctx->f[12] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120bd8) {
            ctx->pc = 0x120BF8u;
            goto label_120bf8;
        }
    }
    ctx->pc = 0x120BE0u;
    // 0x120be0: 0x3c013735  lui         $at, 0x3735
    ctx->pc = 0x120be0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14133 << 16));
    // 0x120be4: 0x34214442  ori         $at, $at, 0x4442
    ctx->pc = 0x120be4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)17474);
    // 0x120be8: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x120be8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120bec: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x120BECu;
    {
        const bool branch_taken_0x120bec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120BECu;
            // 0x120bf0: 0x46026040  add.s       $f1, $f12, $f2 (Delay Slot)
        ctx->f[1] = FPU_ADD_S(ctx->f[12], ctx->f[2]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120bec) {
            ctx->pc = 0x120C18u;
            goto label_120c18;
        }
    }
    ctx->pc = 0x120BF4u;
    // 0x120bf4: 0x0  nop
    ctx->pc = 0x120bf4u;
    // NOP
label_120bf8:
    // 0x120bf8: 0x3c013735  lui         $at, 0x3735
    ctx->pc = 0x120bf8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14133 << 16));
    // 0x120bfc: 0x342143ff  ori         $at, $at, 0x43FF
    ctx->pc = 0x120bfcu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)17407);
    // 0x120c00: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120c00u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120c04: 0x3c012e85  lui         $at, 0x2E85
    ctx->pc = 0x120c04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)11909 << 16));
    // 0x120c08: 0x3421a308  ori         $at, $at, 0xA308
    ctx->pc = 0x120c08u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)41736);
    // 0x120c0c: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x120c0cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120c10: 0x46006300  add.s       $f12, $f12, $f0
    ctx->pc = 0x120c10u;
    ctx->f[12] = FPU_ADD_S(ctx->f[12], ctx->f[0]);
    // 0x120c14: 0x46026040  add.s       $f1, $f12, $f2
    ctx->pc = 0x120c14u;
    ctx->f[1] = FPU_ADD_S(ctx->f[12], ctx->f[2]);
label_120c18:
    // 0x120c18: 0x46016001  sub.s       $f0, $f12, $f1
    ctx->pc = 0x120c18u;
    ctx->f[0] = FPU_SUB_S(ctx->f[12], ctx->f[1]);
    // 0x120c1c: 0xe6210000  swc1        $f1, 0x0($s1)
    ctx->pc = 0x120c1cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x120c20: 0x46020000  add.s       $f0, $f0, $f2
    ctx->pc = 0x120c20u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x120c24: 0xe6200004  swc1        $f0, 0x4($s1)
    ctx->pc = 0x120c24u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 4), bits); }
    // 0x120c28: 0x10000095  b           . + 4 + (0x95 << 2)
    ctx->pc = 0x120C28u;
    {
        const bool branch_taken_0x120c28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120C28u;
            // 0x120c2c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120c28) {
            ctx->pc = 0x120E80u;
            goto label_120e80;
        }
    }
    ctx->pc = 0x120C30u;
label_120c30:
    // 0x120c30: 0x34420f80  ori         $v0, $v0, 0xF80
    ctx->pc = 0x120c30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)3968);
    // 0x120c34: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x120c34u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x120c38: 0x54400061  bnel        $v0, $zero, . + 4 + (0x61 << 2)
    ctx->pc = 0x120C38u;
    {
        const bool branch_taken_0x120c38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x120c38) {
            ctx->pc = 0x120C3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120C38u;
            // 0x120c3c: 0x1015c3  sra         $v0, $s0, 23 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 16), 23));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120DC0u;
            goto label_120dc0;
        }
    }
    ctx->pc = 0x120C40u;
    // 0x120c40: 0xc04892a  jal         func_1224A8
    ctx->pc = 0x120C40u;
    SET_GPR_U32(ctx, 31, 0x120C48u);
    ctx->pc = 0x1224A8u;
    if (runtime->hasFunction(0x1224A8u)) {
        auto targetFn = runtime->lookupFunction(0x1224A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120C48u; }
        if (ctx->pc != 0x120C48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001224A8_0x1224a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120C48u; }
        if (ctx->pc != 0x120C48u) { return; }
    }
    ctx->pc = 0x120C48u;
label_120c48:
    // 0x120c48: 0x3c013f00  lui         $at, 0x3F00
    ctx->pc = 0x120c48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16128 << 16));
    // 0x120c4c: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x120c4cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120c50: 0x46000146  mov.s       $f5, $f0
    ctx->pc = 0x120c50u;
    ctx->f[5] = FPU_MOV_S(ctx->f[0]);
    // 0x120c54: 0x3c013f22  lui         $at, 0x3F22
    ctx->pc = 0x120c54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16162 << 16));
    // 0x120c58: 0x3421f984  ori         $at, $at, 0xF984
    ctx->pc = 0x120c58u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)63876);
    // 0x120c5c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120c5cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120c60: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x120c60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x120c64: 0x34210f80  ori         $at, $at, 0xF80
    ctx->pc = 0x120c64u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)3968);
    // 0x120c68: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120c68u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120c6c: 0x46002802  mul.s       $f0, $f5, $f0
    ctx->pc = 0x120c6cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[5], ctx->f[0]);
    // 0x120c70: 0x3c013735  lui         $at, 0x3735
    ctx->pc = 0x120c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14133 << 16));
    // 0x120c74: 0x34214442  ori         $at, $at, 0x4442
    ctx->pc = 0x120c74u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)17474);
    // 0x120c78: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x120c78u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x120c7c: 0x46020000  add.s       $f0, $f0, $f2
    ctx->pc = 0x120c7cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x120c80: 0x460000a4  .word       0x460000A4                   # cvt.w.s     $f2, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x120c80u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x120c84: 0x44051000  mfc1        $a1, $f2
    ctx->pc = 0x120c84u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x120c88: 0x44853000  mtc1        $a1, $f6
    ctx->pc = 0x120c88u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[6], &bits, sizeof(bits)); }
    // 0x120c8c: 0x468031a0  cvt.s.w     $f6, $f6
    ctx->pc = 0x120c8cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[6], sizeof(tmp)); ctx->f[6] = FPU_CVT_S_W(tmp); }
    // 0x120c90: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x120c90u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x120c94: 0x46013042  mul.s       $f1, $f6, $f1
    ctx->pc = 0x120c94u;
    ctx->f[1] = FPU_MUL_S(ctx->f[6], ctx->f[1]);
    // 0x120c98: 0x460330c2  mul.s       $f3, $f6, $f3
    ctx->pc = 0x120c98u;
    ctx->f[3] = FPU_MUL_S(ctx->f[6], ctx->f[3]);
    // 0x120c9c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x120C9Cu;
    {
        const bool branch_taken_0x120c9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x120CA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120C9Cu;
            // 0x120ca0: 0x46012901  sub.s       $f4, $f5, $f1 (Delay Slot)
        ctx->f[4] = FPU_SUB_S(ctx->f[5], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120c9c) {
            ctx->pc = 0x120CD0u;
            goto label_120cd0;
        }
    }
    ctx->pc = 0x120CA4u;
    // 0x120ca4: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x120ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x120ca8: 0x2403ff00  addiu       $v1, $zero, -0x100
    ctx->pc = 0x120ca8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x120cac: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x120cacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x120cb0: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x120cb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x120cb4: 0x8c8490fc  lw          $a0, -0x6F04($a0)
    ctx->pc = 0x120cb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294938876)));
    // 0x120cb8: 0x2031824  and         $v1, $s0, $v1
    ctx->pc = 0x120cb8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x120cbc: 0x10640005  beq         $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x120CBCu;
    {
        const bool branch_taken_0x120cbc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x120CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120CBCu;
            // 0x120cc0: 0x46032001  sub.s       $f0, $f4, $f3 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120cbc) {
            ctx->pc = 0x120CD4u;
            goto label_120cd4;
        }
    }
    ctx->pc = 0x120CC4u;
    // 0x120cc4: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x120CC4u;
    {
        const bool branch_taken_0x120cc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120CC4u;
            // 0x120cc8: 0xe6200000  swc1        $f0, 0x0($s1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x120cc4) {
            ctx->pc = 0x120D94u;
            goto label_120d94;
        }
    }
    ctx->pc = 0x120CCCu;
    // 0x120ccc: 0x0  nop
    ctx->pc = 0x120cccu;
    // NOP
label_120cd0:
    // 0x120cd0: 0x46032001  sub.s       $f0, $f4, $f3
    ctx->pc = 0x120cd0u;
    ctx->f[0] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
label_120cd4:
    // 0x120cd4: 0x1025c3  sra         $a0, $s0, 23
    ctx->pc = 0x120cd4u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 16), 23));
    // 0x120cd8: 0xe6200000  swc1        $f0, 0x0($s1)
    ctx->pc = 0x120cd8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x120cdc: 0xe7a00010  swc1        $f0, 0x10($sp)
    ctx->pc = 0x120cdcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 16), bits); }
    // 0x120ce0: 0x8fa30010  lw          $v1, 0x10($sp)
    ctx->pc = 0x120ce0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x120ce4: 0x315c2  srl         $v0, $v1, 23
    ctx->pc = 0x120ce4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 23));
    // 0x120ce8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x120ce8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x120cec: 0x821823  subu        $v1, $a0, $v0
    ctx->pc = 0x120cecu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x120cf0: 0x28630009  slti        $v1, $v1, 0x9
    ctx->pc = 0x120cf0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x120cf4: 0x54600028  bnel        $v1, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x120CF4u;
    {
        const bool branch_taken_0x120cf4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x120cf4) {
            ctx->pc = 0x120CF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120CF4u;
            // 0x120cf8: 0xc6210000  lwc1        $f1, 0x0($s1) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
            ctx->pc = 0x120D98u;
            goto label_120d98;
        }
    }
    ctx->pc = 0x120CFCu;
    // 0x120cfc: 0x3c013735  lui         $at, 0x3735
    ctx->pc = 0x120cfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14133 << 16));
    // 0x120d00: 0x342143ff  ori         $at, $at, 0x43FF
    ctx->pc = 0x120d00u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)17407);
    // 0x120d04: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120d04u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120d08: 0x46002146  mov.s       $f5, $f4
    ctx->pc = 0x120d08u;
    ctx->f[5] = FPU_MOV_S(ctx->f[4]);
    // 0x120d0c: 0x3c012e85  lui         $at, 0x2E85
    ctx->pc = 0x120d0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)11909 << 16));
    // 0x120d10: 0x3421a308  ori         $at, $at, 0xA308
    ctx->pc = 0x120d10u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)41736);
    // 0x120d14: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x120d14u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120d18: 0x460030c2  mul.s       $f3, $f6, $f0
    ctx->pc = 0x120d18u;
    ctx->f[3] = FPU_MUL_S(ctx->f[6], ctx->f[0]);
    // 0x120d1c: 0x46023082  mul.s       $f2, $f6, $f2
    ctx->pc = 0x120d1cu;
    ctx->f[2] = FPU_MUL_S(ctx->f[6], ctx->f[2]);
    // 0x120d20: 0x46032101  sub.s       $f4, $f4, $f3
    ctx->pc = 0x120d20u;
    ctx->f[4] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x120d24: 0x46042801  sub.s       $f0, $f5, $f4
    ctx->pc = 0x120d24u;
    ctx->f[0] = FPU_SUB_S(ctx->f[5], ctx->f[4]);
    // 0x120d28: 0x46030001  sub.s       $f0, $f0, $f3
    ctx->pc = 0x120d28u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[3]);
    // 0x120d2c: 0x460010c1  sub.s       $f3, $f2, $f0
    ctx->pc = 0x120d2cu;
    ctx->f[3] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
    // 0x120d30: 0x46032041  sub.s       $f1, $f4, $f3
    ctx->pc = 0x120d30u;
    ctx->f[1] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x120d34: 0xe6210000  swc1        $f1, 0x0($s1)
    ctx->pc = 0x120d34u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x120d38: 0xe7a10014  swc1        $f1, 0x14($sp)
    ctx->pc = 0x120d38u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 20), bits); }
    // 0x120d3c: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x120d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x120d40: 0x315c2  srl         $v0, $v1, 23
    ctx->pc = 0x120d40u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 23));
    // 0x120d44: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x120d44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x120d48: 0x821823  subu        $v1, $a0, $v0
    ctx->pc = 0x120d48u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x120d4c: 0x2863001a  slti        $v1, $v1, 0x1A
    ctx->pc = 0x120d4cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)26) ? 1 : 0);
    // 0x120d50: 0x54600011  bnel        $v1, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x120D50u;
    {
        const bool branch_taken_0x120d50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x120d50) {
            ctx->pc = 0x120D54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120D50u;
            // 0x120d54: 0xc6210000  lwc1        $f1, 0x0($s1) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
            ctx->pc = 0x120D98u;
            goto label_120d98;
        }
    }
    ctx->pc = 0x120D58u;
    // 0x120d58: 0x3c012e85  lui         $at, 0x2E85
    ctx->pc = 0x120d58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)11909 << 16));
    // 0x120d5c: 0x3421a300  ori         $at, $at, 0xA300
    ctx->pc = 0x120d5cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)41728);
    // 0x120d60: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120d60u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120d64: 0x46002146  mov.s       $f5, $f4
    ctx->pc = 0x120d64u;
    ctx->f[5] = FPU_MOV_S(ctx->f[4]);
    // 0x120d68: 0x3c01248d  lui         $at, 0x248D
    ctx->pc = 0x120d68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)9357 << 16));
    // 0x120d6c: 0x34213131  ori         $at, $at, 0x3131
    ctx->pc = 0x120d6cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)12593);
    // 0x120d70: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x120d70u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120d74: 0x460030c2  mul.s       $f3, $f6, $f0
    ctx->pc = 0x120d74u;
    ctx->f[3] = FPU_MUL_S(ctx->f[6], ctx->f[0]);
    // 0x120d78: 0x46023082  mul.s       $f2, $f6, $f2
    ctx->pc = 0x120d78u;
    ctx->f[2] = FPU_MUL_S(ctx->f[6], ctx->f[2]);
    // 0x120d7c: 0x46032101  sub.s       $f4, $f4, $f3
    ctx->pc = 0x120d7cu;
    ctx->f[4] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x120d80: 0x46042801  sub.s       $f0, $f5, $f4
    ctx->pc = 0x120d80u;
    ctx->f[0] = FPU_SUB_S(ctx->f[5], ctx->f[4]);
    // 0x120d84: 0x46030001  sub.s       $f0, $f0, $f3
    ctx->pc = 0x120d84u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[3]);
    // 0x120d88: 0x460010c1  sub.s       $f3, $f2, $f0
    ctx->pc = 0x120d88u;
    ctx->f[3] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
    // 0x120d8c: 0x46032041  sub.s       $f1, $f4, $f3
    ctx->pc = 0x120d8cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x120d90: 0xe6210000  swc1        $f1, 0x0($s1)
    ctx->pc = 0x120d90u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
label_120d94:
    // 0x120d94: 0xc6210000  lwc1        $f1, 0x0($s1)
    ctx->pc = 0x120d94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_120d98:
    // 0x120d98: 0x46012001  sub.s       $f0, $f4, $f1
    ctx->pc = 0x120d98u;
    ctx->f[0] = FPU_SUB_S(ctx->f[4], ctx->f[1]);
    // 0x120d9c: 0x46030001  sub.s       $f0, $f0, $f3
    ctx->pc = 0x120d9cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[3]);
    // 0x120da0: 0x6410005  bgez        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x120DA0u;
    {
        const bool branch_taken_0x120da0 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x120DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120DA0u;
            // 0x120da4: 0xe6200004  swc1        $f0, 0x4($s1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 4), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x120da0) {
            ctx->pc = 0x120DB8u;
            goto label_120db8;
        }
    }
    ctx->pc = 0x120DA8u;
    // 0x120da8: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x120da8u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x120dac: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x120DACu;
    {
        const bool branch_taken_0x120dac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120DB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120DACu;
            // 0x120db0: 0x51023  negu        $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120dac) {
            ctx->pc = 0x120E74u;
            goto label_120e74;
        }
    }
    ctx->pc = 0x120DB4u;
    // 0x120db4: 0x0  nop
    ctx->pc = 0x120db4u;
    // NOP
label_120db8:
    // 0x120db8: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x120DB8u;
    {
        const bool branch_taken_0x120db8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120DB8u;
            // 0x120dbc: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120db8) {
            ctx->pc = 0x120E80u;
            goto label_120e80;
        }
    }
    ctx->pc = 0x120DC0u;
label_120dc0:
    // 0x120dc0: 0x2446ff7a  addiu       $a2, $v0, -0x86
    ctx->pc = 0x120dc0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967162));
    // 0x120dc4: 0x61dc0  sll         $v1, $a2, 23
    ctx->pc = 0x120dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 23));
    // 0x120dc8: 0x2038023  subu        $s0, $s0, $v1
    ctx->pc = 0x120dc8u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x120dcc: 0x44906000  mtc1        $s0, $f12
    ctx->pc = 0x120dccu;
    { uint32_t bits = GPR_U32(ctx, 16); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x120dd0: 0x3c014380  lui         $at, 0x4380
    ctx->pc = 0x120dd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17280 << 16));
    // 0x120dd4: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x120dd4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120dd8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x120dd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x120ddc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x120ddcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_120de0:
    // 0x120de0: 0x46006024  .word       0x46006024                   # cvt.w.s     $f0, $f12 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x120de0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[12]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x120de4: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x120de4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x120de8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x120de8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x120dec: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x120decu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120df0: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x120df0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x120df4: 0x46006041  sub.s       $f1, $f12, $f0
    ctx->pc = 0x120df4u;
    ctx->f[1] = FPU_SUB_S(ctx->f[12], ctx->f[0]);
    // 0x120df8: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x120df8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x120dfc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x120dfcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x120e00: 0x461fff7  bgez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x120E00u;
    {
        const bool branch_taken_0x120e00 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x120E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120E00u;
            // 0x120e04: 0x46020b02  mul.s       $f12, $f1, $f2 (Delay Slot)
        ctx->f[12] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120e00) {
            ctx->pc = 0x120DE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_120de0;
        }
    }
    ctx->pc = 0x120E08u;
    // 0x120e08: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x120e08u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120e0c: 0x46006006  mov.s       $f0, $f12
    ctx->pc = 0x120e0cu;
    ctx->f[0] = FPU_MOV_S(ctx->f[12]);
    // 0x120e10: 0xe7ac0008  swc1        $f12, 0x8($sp)
    ctx->pc = 0x120e10u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x120e14: 0x46010032  c.eq.s      $f0, $f1
    ctx->pc = 0x120e14u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x120e18: 0x4500000a  bc1f        . + 4 + (0xA << 2)
    ctx->pc = 0x120E18u;
    {
        const bool branch_taken_0x120e18 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x120E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120E18u;
            // 0x120e1c: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120e18) {
            ctx->pc = 0x120E44u;
            goto label_120e44;
        }
    }
    ctx->pc = 0x120E20u;
    // 0x120e20: 0x27a20008  addiu       $v0, $sp, 0x8
    ctx->pc = 0x120e20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x120e24: 0x0  nop
    ctx->pc = 0x120e24u;
    // NOP
label_120e28:
    // 0x120e28: 0x2442fffc  addiu       $v0, $v0, -0x4
    ctx->pc = 0x120e28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x120e2c: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x120e2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x120e30: 0x46010032  c.eq.s      $f0, $f1
    ctx->pc = 0x120e30u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x120e34: 0x0  nop
    ctx->pc = 0x120e34u;
    // NOP
    // 0x120e38: 0x0  nop
    ctx->pc = 0x120e38u;
    // NOP
    // 0x120e3c: 0x4501fffa  bc1t        . + 4 + (-0x6 << 2)
    ctx->pc = 0x120E3Cu;
    {
        const bool branch_taken_0x120e3c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x120E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120E3Cu;
            // 0x120e40: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120e3c) {
            ctx->pc = 0x120E28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_120e28;
        }
    }
    ctx->pc = 0x120E44u;
label_120e44:
    // 0x120e44: 0x3c090024  lui         $t1, 0x24
    ctx->pc = 0x120e44u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)36 << 16));
    // 0x120e48: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x120e48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120e4c: 0x25298de8  addiu       $t1, $t1, -0x7218
    ctx->pc = 0x120e4cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294938088));
    // 0x120e50: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x120e50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x120e54: 0xc04842e  jal         func_1210B8
    ctx->pc = 0x120E54u;
    SET_GPR_U32(ctx, 31, 0x120E5Cu);
    ctx->pc = 0x120E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x120E54u;
            // 0x120e58: 0x24080002  addiu       $t0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1210B8u;
    if (runtime->hasFunction(0x1210B8u)) {
        auto targetFn = runtime->lookupFunction(0x1210B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120E5Cu; }
        if (ctx->pc != 0x120E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001210B8_0x1210b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120E5Cu; }
        if (ctx->pc != 0x120E5Cu) { return; }
    }
    ctx->pc = 0x120E5Cu;
label_120e5c:
    // 0x120e5c: 0x6410008  bgez        $s2, . + 4 + (0x8 << 2)
    ctx->pc = 0x120E5Cu;
    {
        const bool branch_taken_0x120e5c = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x120E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120E5Cu;
            // 0x120e60: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120e5c) {
            ctx->pc = 0x120E80u;
            goto label_120e80;
        }
    }
    ctx->pc = 0x120E64u;
    // 0x120e64: 0xc6210000  lwc1        $f1, 0x0($s1)
    ctx->pc = 0x120e64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x120e68: 0x51023  negu        $v0, $a1
    ctx->pc = 0x120e68u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 5)));
    // 0x120e6c: 0xc6200004  lwc1        $f0, 0x4($s1)
    ctx->pc = 0x120e6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x120e70: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x120e70u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
label_120e74:
    // 0x120e74: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x120e74u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x120e78: 0xe6210000  swc1        $f1, 0x0($s1)
    ctx->pc = 0x120e78u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x120e7c: 0xe6200004  swc1        $f0, 0x4($s1)
    ctx->pc = 0x120e7cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 4), bits); }
label_120e80:
    // 0x120e80: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x120e80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x120e84: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x120e84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x120e88: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x120e88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x120e8c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x120e8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x120e90: 0x3e00008  jr          $ra
    ctx->pc = 0x120E90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x120E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120E90u;
            // 0x120e94: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x120B38u: goto label_120b38;
            case 0x120B88u: goto label_120b88;
            case 0x120BA8u: goto label_120ba8;
            case 0x120BC0u: goto label_120bc0;
            case 0x120BF8u: goto label_120bf8;
            case 0x120C18u: goto label_120c18;
            case 0x120C30u: goto label_120c30;
            case 0x120C48u: goto label_120c48;
            case 0x120CD0u: goto label_120cd0;
            case 0x120CD4u: goto label_120cd4;
            case 0x120D94u: goto label_120d94;
            case 0x120D98u: goto label_120d98;
            case 0x120DB8u: goto label_120db8;
            case 0x120DC0u: goto label_120dc0;
            case 0x120DE0u: goto label_120de0;
            case 0x120E28u: goto label_120e28;
            case 0x120E44u: goto label_120e44;
            case 0x120E5Cu: goto label_120e5c;
            case 0x120E74u: goto label_120e74;
            case 0x120E80u: goto label_120e80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x120E98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
