#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00120908
// Address: 0x120908 - 0x120ae8
void sub_00120908_0x120908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00120908_0x120908");
#endif

    switch (ctx->pc) {
        case 0x120a2cu: goto label_120a2c;
        case 0x120a34u: goto label_120a34;
        default: break;
    }

    ctx->pc = 0x120908u;

    // 0x120908: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x120908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12090c: 0x46006046  mov.s       $f1, $f12
    ctx->pc = 0x12090cu;
    ctx->f[1] = FPU_MOV_S(ctx->f[12]);
    // 0x120910: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x120910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x120914: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x120914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x120918: 0x44066800  mfc1        $a2, $f13
    ctx->pc = 0x120918u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[13], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x12091c: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x12091cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x120920: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x120920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x120924: 0xc24024  and         $t0, $a2, $v0
    ctx->pc = 0x120924u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x120928: 0x44050800  mfc1        $a1, $f1
    ctx->pc = 0x120928u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x12092c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x12092cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x120930: 0x14c30005  bne         $a2, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x120930u;
    {
        const bool branch_taken_0x120930 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 3));
        ctx->pc = 0x120934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120930u;
            // 0x120934: 0xa23824  and         $a3, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120930) {
            ctx->pc = 0x120948u;
            goto label_120948;
        }
    }
    ctx->pc = 0x120938u;
    // 0x120938: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x120938u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12093c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12093cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x120940: 0x8048850  j           func_122140
    ctx->pc = 0x120940u;
    ctx->pc = 0x120944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x120940u;
            // 0x120944: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122140u;
    if (runtime->hasFunction(0x122140u)) {
        auto targetFn = runtime->lookupFunction(0x122140u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122140_0x122140(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x120948u;
label_120948:
    // 0x120948: 0x3c02007f  lui         $v0, 0x7F
    ctx->pc = 0x120948u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
    // 0x12094c: 0x62783  sra         $a0, $a2, 30
    ctx->pc = 0x12094cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 6), 30));
    // 0x120950: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x120950u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x120954: 0x30840002  andi        $a0, $a0, 0x2
    ctx->pc = 0x120954u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
    // 0x120958: 0x51fc2  srl         $v1, $a1, 31
    ctx->pc = 0x120958u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 5), 31));
    // 0x12095c: 0x47102a  slt         $v0, $v0, $a3
    ctx->pc = 0x12095cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x120960: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x120960u;
    {
        const bool branch_taken_0x120960 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x120964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120960u;
            // 0x120964: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120960) {
            ctx->pc = 0x1209ACu;
            goto label_1209ac;
        }
    }
    ctx->pc = 0x120968u;
    // 0x120968: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x120968u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12096c: 0x3c014049  lui         $at, 0x4049
    ctx->pc = 0x12096cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16457 << 16));
    // 0x120970: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120970u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x120974: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120974u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120978: 0x12020057  beq         $s0, $v0, . + 4 + (0x57 << 2)
    ctx->pc = 0x120978u;
    {
        const bool branch_taken_0x120978 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x12097Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120978u;
            // 0x12097c: 0x2a020003  slti        $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120978) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120980u;
    // 0x120980: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x120980u;
    {
        const bool branch_taken_0x120980 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x120980) {
            ctx->pc = 0x120984u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120980u;
            // 0x120984: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120998u;
            goto label_120998;
        }
    }
    ctx->pc = 0x120988u;
    // 0x120988: 0x6000009  bltz        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x120988u;
    {
        const bool branch_taken_0x120988 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x12098Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120988u;
            // 0x12098c: 0x3c02007f  lui         $v0, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120988) {
            ctx->pc = 0x1209B0u;
            goto label_1209b0;
        }
    }
    ctx->pc = 0x120990u;
    // 0x120990: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x120990u;
    {
        const bool branch_taken_0x120990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120990u;
            // 0x120994: 0x46000806  mov.s       $f0, $f1 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120990) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120998u;
label_120998:
    // 0x120998: 0x3c01c049  lui         $at, 0xC049
    ctx->pc = 0x120998u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49225 << 16));
    // 0x12099c: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x12099cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x1209a0: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1209a0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1209a4: 0x5202004d  beql        $s0, $v0, . + 4 + (0x4D << 2)
    ctx->pc = 0x1209A4u;
    {
        const bool branch_taken_0x1209a4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x1209a4) {
            ctx->pc = 0x1209A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1209A4u;
            // 0x1209a8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120ADCu;
            goto label_120adc;
        }
    }
    ctx->pc = 0x1209ACu;
label_1209ac:
    // 0x1209ac: 0x3c02007f  lui         $v0, 0x7F
    ctx->pc = 0x1209acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
label_1209b0:
    // 0x1209b0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1209b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1209b4: 0x48102a  slt         $v0, $v0, $t0
    ctx->pc = 0x1209b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1209b8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1209B8u;
    {
        const bool branch_taken_0x1209b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1209BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1209B8u;
            // 0x1209bc: 0xe81823  subu        $v1, $a3, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1209b8) {
            ctx->pc = 0x1209E8u;
            goto label_1209e8;
        }
    }
    ctx->pc = 0x1209C0u;
    // 0x1209c0: 0x3c01bfc9  lui         $at, 0xBFC9
    ctx->pc = 0x1209c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49097 << 16));
    // 0x1209c4: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x1209c4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x1209c8: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1209c8u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1209cc: 0x4a00042  bltz        $a1, . + 4 + (0x42 << 2)
    ctx->pc = 0x1209CCu;
    {
        const bool branch_taken_0x1209cc = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x1209D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1209CCu;
            // 0x1209d0: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1209cc) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x1209D4u;
    // 0x1209d4: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x1209d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x1209d8: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x1209d8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x1209dc: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1209dcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1209e0: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x1209E0u;
    {
        const bool branch_taken_0x1209e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1209E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1209E0u;
            // 0x1209e4: 0xdfbf0018  ld          $ra, 0x18($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1209e0) {
            ctx->pc = 0x120AE0u;
            goto label_120ae0;
        }
    }
    ctx->pc = 0x1209E8u;
label_1209e8:
    // 0x1209e8: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x1209e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x1209ec: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x1209ecu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x1209f0: 0x44811000  mtc1        $at, $f2
    ctx->pc = 0x1209f0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1209f4: 0x31dc3  sra         $v1, $v1, 23
    ctx->pc = 0x1209f4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 23));
    // 0x1209f8: 0x2862003d  slti        $v0, $v1, 0x3D
    ctx->pc = 0x1209f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)61) ? 1 : 0);
    // 0x1209fc: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1209FCu;
    {
        const bool branch_taken_0x1209fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x120A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1209FCu;
            // 0x120a00: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1209fc) {
            ctx->pc = 0x120A3Cu;
            goto label_120a3c;
        }
    }
    ctx->pc = 0x120A04u;
    // 0x120a04: 0x4c10004  bgez        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x120A04u;
    {
        const bool branch_taken_0x120a04 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x120A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A04u;
            // 0x120a08: 0x2862ffc4  slti        $v0, $v1, -0x3C (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4294967236) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a04) {
            ctx->pc = 0x120A18u;
            goto label_120a18;
        }
    }
    ctx->pc = 0x120A0Cu;
    // 0x120a0c: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x120a0cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120a10: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x120A10u;
    {
        const bool branch_taken_0x120a10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x120A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A10u;
            // 0x120a14: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a10) {
            ctx->pc = 0x120A3Cu;
            goto label_120a3c;
        }
    }
    ctx->pc = 0x120A18u;
label_120a18:
    // 0x120a18: 0x0  nop
    ctx->pc = 0x120a18u;
    // NOP
    // 0x120a1c: 0x0  nop
    ctx->pc = 0x120a1cu;
    // NOP
    // 0x120a20: 0x460d0b03  div.s       $f12, $f1, $f13
    ctx->pc = 0x120a20u;
    if (ctx->f[13] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[13])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[1] / ctx->f[13];
    // 0x120a24: 0xc04892a  jal         func_1224A8
    ctx->pc = 0x120A24u;
    SET_GPR_U32(ctx, 31, 0x120A2Cu);
    ctx->pc = 0x1224A8u;
    if (runtime->hasFunction(0x1224A8u)) {
        auto targetFn = runtime->lookupFunction(0x1224A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120A2Cu; }
        if (ctx->pc != 0x120A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001224A8_0x1224a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120A2Cu; }
        if (ctx->pc != 0x120A2Cu) { return; }
    }
    ctx->pc = 0x120A2Cu;
label_120a2c:
    // 0x120a2c: 0xc048850  jal         func_122140
    ctx->pc = 0x120A2Cu;
    SET_GPR_U32(ctx, 31, 0x120A34u);
    ctx->pc = 0x120A30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x120A2Cu;
            // 0x120a30: 0x46000306  mov.s       $f12, $f0 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x122140u;
    if (runtime->hasFunction(0x122140u)) {
        auto targetFn = runtime->lookupFunction(0x122140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120A34u; }
        if (ctx->pc != 0x120A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00122140_0x122140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x120A34u; }
        if (ctx->pc != 0x120A34u) { return; }
    }
    ctx->pc = 0x120A34u;
label_120a34:
    // 0x120a34: 0x46000086  mov.s       $f2, $f0
    ctx->pc = 0x120a34u;
    ctx->f[2] = FPU_MOV_S(ctx->f[0]);
    // 0x120a38: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x120a38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_120a3c:
    // 0x120a3c: 0x1202000c  beq         $s0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x120A3Cu;
    {
        const bool branch_taken_0x120a3c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x120A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A3Cu;
            // 0x120a40: 0x2a020002  slti        $v0, $s0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a3c) {
            ctx->pc = 0x120A70u;
            goto label_120a70;
        }
    }
    ctx->pc = 0x120A44u;
    // 0x120a44: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x120A44u;
    {
        const bool branch_taken_0x120a44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x120a44) {
            ctx->pc = 0x120A48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x120A44u;
            // 0x120a48: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x120A60u;
            goto label_120a60;
        }
    }
    ctx->pc = 0x120A4Cu;
    // 0x120a4c: 0x12000022  beqz        $s0, . + 4 + (0x22 << 2)
    ctx->pc = 0x120A4Cu;
    {
        const bool branch_taken_0x120a4c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x120A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A4Cu;
            // 0x120a50: 0x46001006  mov.s       $f0, $f2 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[2]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a4c) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120A54u;
    // 0x120a54: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x120A54u;
    {
        const bool branch_taken_0x120a54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x120a54) {
            ctx->pc = 0x120AB8u;
            goto label_120ab8;
        }
    }
    ctx->pc = 0x120A5Cu;
    // 0x120a5c: 0x0  nop
    ctx->pc = 0x120a5cu;
    // NOP
label_120a60:
    // 0x120a60: 0x1202000b  beq         $s0, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x120A60u;
    {
        const bool branch_taken_0x120a60 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x120a60) {
            ctx->pc = 0x120A90u;
            goto label_120a90;
        }
    }
    ctx->pc = 0x120A68u;
    // 0x120a68: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x120A68u;
    {
        const bool branch_taken_0x120a68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x120a68) {
            ctx->pc = 0x120AB8u;
            goto label_120ab8;
        }
    }
    ctx->pc = 0x120A70u;
label_120a70:
    // 0x120a70: 0xe7a20000  swc1        $f2, 0x0($sp)
    ctx->pc = 0x120a70u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x120a74: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x120a74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x120a78: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x120a78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x120a7c: 0x621826  xor         $v1, $v1, $v0
    ctx->pc = 0x120a7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x120a80: 0x44831000  mtc1        $v1, $f2
    ctx->pc = 0x120a80u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x120a84: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x120A84u;
    {
        const bool branch_taken_0x120a84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120A84u;
            // 0x120a88: 0x46001006  mov.s       $f0, $f2 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[2]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120a84) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120A8Cu;
    // 0x120a8c: 0x0  nop
    ctx->pc = 0x120a8cu;
    // NOP
label_120a90:
    // 0x120a90: 0x3c013422  lui         $at, 0x3422
    ctx->pc = 0x120a90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)13346 << 16));
    // 0x120a94: 0x34212168  ori         $at, $at, 0x2168
    ctx->pc = 0x120a94u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)8552);
    // 0x120a98: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120a98u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120a9c: 0x3c014049  lui         $at, 0x4049
    ctx->pc = 0x120a9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16457 << 16));
    // 0x120aa0: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120aa0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x120aa4: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120aa4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120aa8: 0x46001001  sub.s       $f0, $f2, $f0
    ctx->pc = 0x120aa8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
    // 0x120aac: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x120AACu;
    {
        const bool branch_taken_0x120aac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x120AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120AACu;
            // 0x120ab0: 0x46000801  sub.s       $f0, $f1, $f0 (Delay Slot)
        ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x120aac) {
            ctx->pc = 0x120AD8u;
            goto label_120ad8;
        }
    }
    ctx->pc = 0x120AB4u;
    // 0x120ab4: 0x0  nop
    ctx->pc = 0x120ab4u;
    // NOP
label_120ab8:
    // 0x120ab8: 0x3c013422  lui         $at, 0x3422
    ctx->pc = 0x120ab8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)13346 << 16));
    // 0x120abc: 0x34212168  ori         $at, $at, 0x2168
    ctx->pc = 0x120abcu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)8552);
    // 0x120ac0: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x120ac0u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x120ac4: 0x3c014049  lui         $at, 0x4049
    ctx->pc = 0x120ac4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16457 << 16));
    // 0x120ac8: 0x34210fda  ori         $at, $at, 0xFDA
    ctx->pc = 0x120ac8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4058);
    // 0x120acc: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x120accu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x120ad0: 0x46001001  sub.s       $f0, $f2, $f0
    ctx->pc = 0x120ad0u;
    ctx->f[0] = FPU_SUB_S(ctx->f[2], ctx->f[0]);
    // 0x120ad4: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x120ad4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
label_120ad8:
    // 0x120ad8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x120ad8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_120adc:
    // 0x120adc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x120adcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_120ae0:
    // 0x120ae0: 0x3e00008  jr          $ra
    ctx->pc = 0x120AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x120AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x120AE0u;
            // 0x120ae4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x120948u: goto label_120948;
            case 0x120998u: goto label_120998;
            case 0x1209ACu: goto label_1209ac;
            case 0x1209B0u: goto label_1209b0;
            case 0x1209E8u: goto label_1209e8;
            case 0x120A18u: goto label_120a18;
            case 0x120A2Cu: goto label_120a2c;
            case 0x120A34u: goto label_120a34;
            case 0x120A3Cu: goto label_120a3c;
            case 0x120A60u: goto label_120a60;
            case 0x120A70u: goto label_120a70;
            case 0x120A90u: goto label_120a90;
            case 0x120AB8u: goto label_120ab8;
            case 0x120AD8u: goto label_120ad8;
            case 0x120ADCu: goto label_120adc;
            case 0x120AE0u: goto label_120ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x120AE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
