#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001071D8
// Address: 0x1071d8 - 0x107900
void sub_001071D8_0x1071d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001071D8_0x1071d8");
#endif

    switch (ctx->pc) {
        case 0x10721cu: goto label_10721c;
        case 0x107308u: goto label_107308;
        case 0x107530u: goto label_107530;
        case 0x1075c8u: goto label_1075c8;
        case 0x1075f8u: goto label_1075f8;
        case 0x107608u: goto label_107608;
        case 0x107618u: goto label_107618;
        case 0x107698u: goto label_107698;
        case 0x1076f0u: goto label_1076f0;
        case 0x107790u: goto label_107790;
        case 0x1077f8u: goto label_1077f8;
        case 0x1078dcu: goto label_1078dc;
        default: break;
    }

    ctx->pc = 0x1071d8u;

    // 0x1071d8: 0x24a30013  addiu       $v1, $a1, 0x13
    ctx->pc = 0x1071d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 19));
    // 0x1071dc: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1071dcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1071e0: 0x2c62001f  sltiu       $v0, $v1, 0x1F
    ctx->pc = 0x1071e0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)31) ? 1 : 0);
    // 0x1071e4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1071e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1071e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1071e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1071ec: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1071ecu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1071f0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1071f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1071f4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1071f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1071f8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1071f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1071fc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1071FCu;
    {
        const bool branch_taken_0x1071fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1071FCu;
            // 0x107200: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1071fc) {
            ctx->pc = 0x107210u;
            goto label_107210;
        }
    }
    ctx->pc = 0x107204u;
    // 0x107204: 0x2402fff0  addiu       $v0, $zero, -0x10
    ctx->pc = 0x107204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x107208: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x107208u;
    {
        const bool branch_taken_0x107208 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10720Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107208u;
            // 0x10720c: 0x628824  and         $s1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107208) {
            ctx->pc = 0x107214u;
            goto label_107214;
        }
    }
    ctx->pc = 0x107210u;
label_107210:
    // 0x107210: 0x24110010  addiu       $s1, $zero, 0x10
    ctx->pc = 0x107210u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_107214:
    // 0x107214: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x107214u;
    SET_GPR_U32(ctx, 31, 0x10721Cu);
    ctx->pc = 0x107218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x107214u;
            // 0x107218: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10721Cu; }
        if (ctx->pc != 0x10721Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10721Cu; }
        if (ctx->pc != 0x10721Cu) { return; }
    }
    ctx->pc = 0x10721Cu;
label_10721c:
    // 0x10721c: 0x2e2201f8  sltiu       $v0, $s1, 0x1F8
    ctx->pc = 0x10721cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)504) ? 1 : 0);
    // 0x107220: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x107220u;
    {
        const bool branch_taken_0x107220 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107220u;
            // 0x107224: 0x111a42  srl         $v1, $s1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 17), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107220) {
            ctx->pc = 0x107280u;
            goto label_107280;
        }
    }
    ctx->pc = 0x107228u;
    // 0x107228: 0x3c0f0021  lui         $t7, 0x21
    ctx->pc = 0x107228u;
    SET_GPR_S32(ctx, 15, (int32_t)((uint32_t)33 << 16));
    // 0x10722c: 0x25e29808  addiu       $v0, $t7, -0x67F8
    ctx->pc = 0x10722cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 15), 4294940680));
    // 0x107230: 0x2442fff8  addiu       $v0, $v0, -0x8
    ctx->pc = 0x107230u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
    // 0x107234: 0x2222021  addu        $a0, $s1, $v0
    ctx->pc = 0x107234u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x107238: 0x8c90000c  lw          $s0, 0xC($a0)
    ctx->pc = 0x107238u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x10723c: 0x1204000e  beq         $s0, $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x10723Cu;
    {
        const bool branch_taken_0x10723c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x107240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10723Cu;
            // 0x107240: 0x1150c2  srl         $t2, $s1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 17), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10723c) {
            ctx->pc = 0x107278u;
            goto label_107278;
        }
    }
    ctx->pc = 0x107244u;
    // 0x107244: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x107244u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x107248: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x107248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x10724c: 0x8e0b000c  lw          $t3, 0xC($s0)
    ctx->pc = 0x10724cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x107250: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x107250u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107254: 0x623024  and         $a2, $v1, $v0
    ctx->pc = 0x107254u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x107258: 0x8e080008  lw          $t0, 0x8($s0)
    ctx->pc = 0x107258u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x10725c: 0x2061821  addu        $v1, $s0, $a2
    ctx->pc = 0x10725cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
    // 0x107260: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x107260u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x107264: 0xad0b000c  sw          $t3, 0xC($t0)
    ctx->pc = 0x107264u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 11));
    // 0x107268: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x107268u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x10726c: 0xad680008  sw          $t0, 0x8($t3)
    ctx->pc = 0x10726cu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 8), GPR_U32(ctx, 8));
    // 0x107270: 0x10000198  b           . + 4 + (0x198 << 2)
    ctx->pc = 0x107270u;
    {
        const bool branch_taken_0x107270 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107270u;
            // 0x107274: 0xac620004  sw          $v0, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107270) {
            ctx->pc = 0x1078D4u;
            goto label_1078d4;
        }
    }
    ctx->pc = 0x107278u;
label_107278:
    // 0x107278: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x107278u;
    {
        const bool branch_taken_0x107278 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10727Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107278u;
            // 0x10727c: 0x254a0002  addiu       $t2, $t2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107278) {
            ctx->pc = 0x10735Cu;
            goto label_10735c;
        }
    }
    ctx->pc = 0x107280u;
label_107280:
    // 0x107280: 0x10600019  beqz        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x107280u;
    {
        const bool branch_taken_0x107280 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x107284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107280u;
            // 0x107284: 0x1150c2  srl         $t2, $s1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 17), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107280) {
            ctx->pc = 0x1072E8u;
            goto label_1072e8;
        }
    }
    ctx->pc = 0x107288u;
    // 0x107288: 0x2c620005  sltiu       $v0, $v1, 0x5
    ctx->pc = 0x107288u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x10728c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10728Cu;
    {
        const bool branch_taken_0x10728c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10728Cu;
            // 0x107290: 0x2c620015  sltiu       $v0, $v1, 0x15 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)21) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10728c) {
            ctx->pc = 0x1072A0u;
            goto label_1072a0;
        }
    }
    ctx->pc = 0x107294u;
    // 0x107294: 0x111182  srl         $v0, $s1, 6
    ctx->pc = 0x107294u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 6));
    // 0x107298: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x107298u;
    {
        const bool branch_taken_0x107298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10729Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107298u;
            // 0x10729c: 0x244a0038  addiu       $t2, $v0, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107298) {
            ctx->pc = 0x1072E8u;
            goto label_1072e8;
        }
    }
    ctx->pc = 0x1072A0u;
label_1072a0:
    // 0x1072a0: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1072A0u;
    {
        const bool branch_taken_0x1072a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1072A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1072A0u;
            // 0x1072a4: 0x246a005b  addiu       $t2, $v1, 0x5B (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 3), 91));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1072a0) {
            ctx->pc = 0x1072E8u;
            goto label_1072e8;
        }
    }
    ctx->pc = 0x1072A8u;
    // 0x1072a8: 0x2c620055  sltiu       $v0, $v1, 0x55
    ctx->pc = 0x1072a8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)85) ? 1 : 0);
    // 0x1072ac: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1072ACu;
    {
        const bool branch_taken_0x1072ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1072B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1072ACu;
            // 0x1072b0: 0x2c620155  sltiu       $v0, $v1, 0x155 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)341) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1072ac) {
            ctx->pc = 0x1072C0u;
            goto label_1072c0;
        }
    }
    ctx->pc = 0x1072B4u;
    // 0x1072b4: 0x111302  srl         $v0, $s1, 12
    ctx->pc = 0x1072b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 12));
    // 0x1072b8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1072B8u;
    {
        const bool branch_taken_0x1072b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1072BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1072B8u;
            // 0x1072bc: 0x244a006e  addiu       $t2, $v0, 0x6E (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 110));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1072b8) {
            ctx->pc = 0x1072E8u;
            goto label_1072e8;
        }
    }
    ctx->pc = 0x1072C0u;
label_1072c0:
    // 0x1072c0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1072C0u;
    {
        const bool branch_taken_0x1072c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1072C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1072C0u;
            // 0x1072c4: 0x2c620555  sltiu       $v0, $v1, 0x555 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)1365) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1072c0) {
            ctx->pc = 0x1072D8u;
            goto label_1072d8;
        }
    }
    ctx->pc = 0x1072C8u;
    // 0x1072c8: 0x1113c2  srl         $v0, $s1, 15
    ctx->pc = 0x1072c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 15));
    // 0x1072cc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1072CCu;
    {
        const bool branch_taken_0x1072cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1072D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1072CCu;
            // 0x1072d0: 0x244a0077  addiu       $t2, $v0, 0x77 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 119));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1072cc) {
            ctx->pc = 0x1072E8u;
            goto label_1072e8;
        }
    }
    ctx->pc = 0x1072D4u;
    // 0x1072d4: 0x0  nop
    ctx->pc = 0x1072d4u;
    // NOP
label_1072d8:
    // 0x1072d8: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x1072D8u;
    {
        const bool branch_taken_0x1072d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1072d8) {
            ctx->pc = 0x1072DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1072D8u;
            // 0x1072dc: 0x240a007e  addiu       $t2, $zero, 0x7E (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 126));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1072E8u;
            goto label_1072e8;
        }
    }
    ctx->pc = 0x1072E0u;
    // 0x1072e0: 0x111482  srl         $v0, $s1, 18
    ctx->pc = 0x1072e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 18));
    // 0x1072e4: 0x244a007c  addiu       $t2, $v0, 0x7C
    ctx->pc = 0x1072e4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 124));
label_1072e8:
    // 0x1072e8: 0x3c0f0021  lui         $t7, 0x21
    ctx->pc = 0x1072e8u;
    SET_GPR_S32(ctx, 15, (int32_t)((uint32_t)33 << 16));
    // 0x1072ec: 0xa18c0  sll         $v1, $t2, 3
    ctx->pc = 0x1072ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x1072f0: 0x25e29808  addiu       $v0, $t7, -0x67F8
    ctx->pc = 0x1072f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 15), 4294940680));
    // 0x1072f4: 0x2404fffc  addiu       $a0, $zero, -0x4
    ctx->pc = 0x1072f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1072f8: 0x2442fff8  addiu       $v0, $v0, -0x8
    ctx->pc = 0x1072f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
    // 0x1072fc: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x1072fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x107300: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x107300u;
    {
        const bool branch_taken_0x107300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107300u;
            // 0x107304: 0x8cb0000c  lw          $s0, 0xC($a1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107300) {
            ctx->pc = 0x107314u;
            goto label_107314;
        }
    }
    ctx->pc = 0x107308u;
label_107308:
    // 0x107308: 0x501013d  bgez        $t0, . + 4 + (0x13D << 2)
    ctx->pc = 0x107308u;
    {
        const bool branch_taken_0x107308 = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x10730Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107308u;
            // 0x10730c: 0x2061821  addu        $v1, $s0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107308) {
            ctx->pc = 0x107800u;
            goto label_107800;
        }
    }
    ctx->pc = 0x107310u;
    // 0x107310: 0x8e10000c  lw          $s0, 0xC($s0)
    ctx->pc = 0x107310u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_107314:
    // 0x107314: 0x52050011  beql        $s0, $a1, . + 4 + (0x11 << 2)
    ctx->pc = 0x107314u;
    {
        const bool branch_taken_0x107314 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 5));
        if (branch_taken_0x107314) {
            ctx->pc = 0x107318u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107314u;
            // 0x107318: 0x254a0001  addiu       $t2, $t2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10735Cu;
            goto label_10735c;
        }
    }
    ctx->pc = 0x10731Cu;
    // 0x10731c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x10731cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x107320: 0x443024  and         $a2, $v0, $a0
    ctx->pc = 0x107320u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x107324: 0x2261823  subu        $v1, $s1, $a2
    ctx->pc = 0x107324u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 6)));
    // 0x107328: 0xd11023  subu        $v0, $a2, $s1
    ctx->pc = 0x107328u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x10732c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10732cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x107330: 0x2383c  dsll32      $a3, $v0, 0
    ctx->pc = 0x107330u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 0));
    // 0x107334: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x107334u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x107338: 0xd1102b  sltu        $v0, $a2, $s1
    ctx->pc = 0x107338u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x10733c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x10733Cu;
    {
        const bool branch_taken_0x10733c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10733Cu;
            // 0x107340: 0x3402f  dsubu       $t0, $zero, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) - GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10733c) {
            ctx->pc = 0x107348u;
            goto label_107348;
        }
    }
    ctx->pc = 0x107344u;
    // 0x107344: 0x7403e  dsrl32      $t0, $a3, 0
    ctx->pc = 0x107344u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 7) >> (32 + 0));
label_107348:
    // 0x107348: 0x29020010  slti        $v0, $t0, 0x10
    ctx->pc = 0x107348u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x10734c: 0x1440ffee  bnez        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x10734Cu;
    {
        const bool branch_taken_0x10734c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10734c) {
            ctx->pc = 0x107308u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107308;
        }
    }
    ctx->pc = 0x107354u;
    // 0x107354: 0x254affff  addiu       $t2, $t2, -0x1
    ctx->pc = 0x107354u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967295));
    // 0x107358: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x107358u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
label_10735c:
    // 0x10735c: 0x25e29808  addiu       $v0, $t7, -0x67F8
    ctx->pc = 0x10735cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 15), 4294940680));
    // 0x107360: 0x8c500008  lw          $s0, 0x8($v0)
    ctx->pc = 0x107360u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x107364: 0x12020080  beq         $s0, $v0, . + 4 + (0x80 << 2)
    ctx->pc = 0x107364u;
    {
        const bool branch_taken_0x107364 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x107368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107364u;
            // 0x107368: 0x2403fffc  addiu       $v1, $zero, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107364) {
            ctx->pc = 0x107568u;
            goto label_107568;
        }
    }
    ctx->pc = 0x10736Cu;
    // 0x10736c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x10736cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x107370: 0x433024  and         $a2, $v0, $v1
    ctx->pc = 0x107370u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x107374: 0xd1202b  sltu        $a0, $a2, $s1
    ctx->pc = 0x107374u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x107378: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x107378u;
    {
        const bool branch_taken_0x107378 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10737Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107378u;
            // 0x10737c: 0xd11023  subu        $v0, $a2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107378) {
            ctx->pc = 0x107398u;
            goto label_107398;
        }
    }
    ctx->pc = 0x107380u;
    // 0x107380: 0x2261023  subu        $v0, $s1, $a2
    ctx->pc = 0x107380u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 6)));
    // 0x107384: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x107384u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x107388: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x107388u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x10738c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x10738Cu;
    {
        const bool branch_taken_0x10738c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10738Cu;
            // 0x107390: 0x2402f  dsubu       $t0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10738c) {
            ctx->pc = 0x1073A0u;
            goto label_1073a0;
        }
    }
    ctx->pc = 0x107394u;
    // 0x107394: 0x0  nop
    ctx->pc = 0x107394u;
    // NOP
label_107398:
    // 0x107398: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x107398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10739c: 0x2403e  dsrl32      $t0, $v0, 0
    ctx->pc = 0x10739cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) >> (32 + 0));
label_1073a0:
    // 0x1073a0: 0x29020010  slti        $v0, $t0, 0x10
    ctx->pc = 0x1073a0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1073a4: 0x54400014  bnel        $v0, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x1073A4u;
    {
        const bool branch_taken_0x1073a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1073a4) {
            ctx->pc = 0x1073A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1073A4u;
            // 0x1073a8: 0x25e49808  addiu       $a0, $t7, -0x67F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 15), 4294940680));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1073F8u;
            goto label_1073f8;
        }
    }
    ctx->pc = 0x1073ACu;
    // 0x1073ac: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1073acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1073b0: 0x2114821  addu        $t1, $s0, $s1
    ctx->pc = 0x1073b0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1073b4: 0x8383c  dsll32      $a3, $t0, 0
    ctx->pc = 0x1073b4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 8) << (32 + 0));
    // 0x1073b8: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x1073b8u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x1073bc: 0x1031825  or          $v1, $t0, $v1
    ctx->pc = 0x1073bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1073c0: 0x25e59808  addiu       $a1, $t7, -0x67F8
    ctx->pc = 0x1073c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 15), 4294940680));
    // 0x1073c4: 0x36220001  ori         $v0, $s1, 0x1
    ctx->pc = 0x1073c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)1);
    // 0x1073c8: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1073c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1073cc: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1073ccu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1073d0: 0x1273021  addu        $a2, $t1, $a3
    ctx->pc = 0x1073d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 7)));
    // 0x1073d4: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1073d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1073d8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1073d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1073dc: 0xaca9000c  sw          $t1, 0xC($a1)
    ctx->pc = 0x1073dcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 9));
    // 0x1073e0: 0xaca90008  sw          $t1, 0x8($a1)
    ctx->pc = 0x1073e0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 9));
    // 0x1073e4: 0xad230004  sw          $v1, 0x4($t1)
    ctx->pc = 0x1073e4u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4), GPR_U32(ctx, 3));
    // 0x1073e8: 0xad250008  sw          $a1, 0x8($t1)
    ctx->pc = 0x1073e8u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 8), GPR_U32(ctx, 5));
    // 0x1073ec: 0xacc70000  sw          $a3, 0x0($a2)
    ctx->pc = 0x1073ecu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 7));
    // 0x1073f0: 0x10000138  b           . + 4 + (0x138 << 2)
    ctx->pc = 0x1073F0u;
    {
        const bool branch_taken_0x1073f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1073F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1073F0u;
            // 0x1073f4: 0xad25000c  sw          $a1, 0xC($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1073f0) {
            ctx->pc = 0x1078D4u;
            goto label_1078d4;
        }
    }
    ctx->pc = 0x1073F8u;
label_1073f8:
    // 0x1073f8: 0xac84000c  sw          $a0, 0xC($a0)
    ctx->pc = 0x1073f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 4));
    // 0x1073fc: 0x5000008  bltz        $t0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1073FCu;
    {
        const bool branch_taken_0x1073fc = (GPR_S64(ctx, 8) < 0);
        ctx->pc = 0x107400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1073FCu;
            // 0x107400: 0xac840008  sw          $a0, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1073fc) {
            ctx->pc = 0x107420u;
            goto label_107420;
        }
    }
    ctx->pc = 0x107404u;
    // 0x107404: 0x2061821  addu        $v1, $s0, $a2
    ctx->pc = 0x107404u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
    // 0x107408: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x107408u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10740c: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x10740cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x107410: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x107410u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x107414: 0x1000012f  b           . + 4 + (0x12F << 2)
    ctx->pc = 0x107414u;
    {
        const bool branch_taken_0x107414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107414u;
            // 0x107418: 0xac620004  sw          $v0, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107414) {
            ctx->pc = 0x1078D4u;
            goto label_1078d4;
        }
    }
    ctx->pc = 0x10741Cu;
    // 0x10741c: 0x0  nop
    ctx->pc = 0x10741cu;
    // NOP
label_107420:
    // 0x107420: 0x2cc20200  sltiu       $v0, $a2, 0x200
    ctx->pc = 0x107420u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)512) ? 1 : 0);
    // 0x107424: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x107424u;
    {
        const bool branch_taken_0x107424 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107424u;
            // 0x107428: 0x61a42  srl         $v1, $a2, 9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 6), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107424) {
            ctx->pc = 0x107470u;
            goto label_107470;
        }
    }
    ctx->pc = 0x10742Cu;
    // 0x10742c: 0x628c2  srl         $a1, $a2, 3
    ctx->pc = 0x10742cu;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 6), 3));
    // 0x107430: 0x2484fff8  addiu       $a0, $a0, -0x8
    ctx->pc = 0x107430u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967288));
    // 0x107434: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x107434u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x107438: 0x52882  srl         $a1, $a1, 2
    ctx->pc = 0x107438u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 2));
    // 0x10743c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10743cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x107440: 0x645821  addu        $t3, $v1, $a0
    ctx->pc = 0x107440u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x107444: 0xa21014  dsllv       $v0, $v0, $a1
    ctx->pc = 0x107444u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 5) & 0x3F));
    // 0x107448: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x107448u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x10744c: 0x8d680008  lw          $t0, 0x8($t3)
    ctx->pc = 0x10744cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x107450: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x107450u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x107454: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x107454u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x107458: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x107458u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x10745c: 0xae0b000c  sw          $t3, 0xC($s0)
    ctx->pc = 0x10745cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 11));
    // 0x107460: 0xae080008  sw          $t0, 0x8($s0)
    ctx->pc = 0x107460u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 8));
    // 0x107464: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x107464u;
    {
        const bool branch_taken_0x107464 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107464u;
            // 0x107468: 0xac830004  sw          $v1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107464) {
            ctx->pc = 0x107560u;
            goto label_107560;
        }
    }
    ctx->pc = 0x10746Cu;
    // 0x10746c: 0x0  nop
    ctx->pc = 0x10746cu;
    // NOP
label_107470:
    // 0x107470: 0x10600019  beqz        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x107470u;
    {
        const bool branch_taken_0x107470 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x107474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107470u;
            // 0x107474: 0x628c2  srl         $a1, $a2, 3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 6), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107470) {
            ctx->pc = 0x1074D8u;
            goto label_1074d8;
        }
    }
    ctx->pc = 0x107478u;
    // 0x107478: 0x2c620005  sltiu       $v0, $v1, 0x5
    ctx->pc = 0x107478u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x10747c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10747Cu;
    {
        const bool branch_taken_0x10747c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10747Cu;
            // 0x107480: 0x2c620015  sltiu       $v0, $v1, 0x15 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)21) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10747c) {
            ctx->pc = 0x107490u;
            goto label_107490;
        }
    }
    ctx->pc = 0x107484u;
    // 0x107484: 0x61182  srl         $v0, $a2, 6
    ctx->pc = 0x107484u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 6));
    // 0x107488: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x107488u;
    {
        const bool branch_taken_0x107488 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10748Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107488u;
            // 0x10748c: 0x24450038  addiu       $a1, $v0, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107488) {
            ctx->pc = 0x1074D8u;
            goto label_1074d8;
        }
    }
    ctx->pc = 0x107490u;
label_107490:
    // 0x107490: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x107490u;
    {
        const bool branch_taken_0x107490 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107490u;
            // 0x107494: 0x2465005b  addiu       $a1, $v1, 0x5B (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 91));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107490) {
            ctx->pc = 0x1074D8u;
            goto label_1074d8;
        }
    }
    ctx->pc = 0x107498u;
    // 0x107498: 0x2c620055  sltiu       $v0, $v1, 0x55
    ctx->pc = 0x107498u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)85) ? 1 : 0);
    // 0x10749c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10749Cu;
    {
        const bool branch_taken_0x10749c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1074A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10749Cu;
            // 0x1074a0: 0x2c620155  sltiu       $v0, $v1, 0x155 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)341) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10749c) {
            ctx->pc = 0x1074B0u;
            goto label_1074b0;
        }
    }
    ctx->pc = 0x1074A4u;
    // 0x1074a4: 0x61302  srl         $v0, $a2, 12
    ctx->pc = 0x1074a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 12));
    // 0x1074a8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1074A8u;
    {
        const bool branch_taken_0x1074a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1074ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1074A8u;
            // 0x1074ac: 0x2445006e  addiu       $a1, $v0, 0x6E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 110));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1074a8) {
            ctx->pc = 0x1074D8u;
            goto label_1074d8;
        }
    }
    ctx->pc = 0x1074B0u;
label_1074b0:
    // 0x1074b0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1074B0u;
    {
        const bool branch_taken_0x1074b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1074B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1074B0u;
            // 0x1074b4: 0x2c620555  sltiu       $v0, $v1, 0x555 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)1365) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1074b0) {
            ctx->pc = 0x1074C8u;
            goto label_1074c8;
        }
    }
    ctx->pc = 0x1074B8u;
    // 0x1074b8: 0x613c2  srl         $v0, $a2, 15
    ctx->pc = 0x1074b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 15));
    // 0x1074bc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1074BCu;
    {
        const bool branch_taken_0x1074bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1074C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1074BCu;
            // 0x1074c0: 0x24450077  addiu       $a1, $v0, 0x77 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 119));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1074bc) {
            ctx->pc = 0x1074D8u;
            goto label_1074d8;
        }
    }
    ctx->pc = 0x1074C4u;
    // 0x1074c4: 0x0  nop
    ctx->pc = 0x1074c4u;
    // NOP
label_1074c8:
    // 0x1074c8: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x1074C8u;
    {
        const bool branch_taken_0x1074c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1074c8) {
            ctx->pc = 0x1074CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1074C8u;
            // 0x1074cc: 0x2405007e  addiu       $a1, $zero, 0x7E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 126));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1074D8u;
            goto label_1074d8;
        }
    }
    ctx->pc = 0x1074D0u;
    // 0x1074d0: 0x61482  srl         $v0, $a2, 18
    ctx->pc = 0x1074d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 18));
    // 0x1074d4: 0x2445007c  addiu       $a1, $v0, 0x7C
    ctx->pc = 0x1074d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 124));
label_1074d8:
    // 0x1074d8: 0x25e29808  addiu       $v0, $t7, -0x67F8
    ctx->pc = 0x1074d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 15), 4294940680));
    // 0x1074dc: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x1074dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1074e0: 0x2447fff8  addiu       $a3, $v0, -0x8
    ctx->pc = 0x1074e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
    // 0x1074e4: 0x675821  addu        $t3, $v1, $a3
    ctx->pc = 0x1074e4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1074e8: 0x8d680008  lw          $t0, 0x8($t3)
    ctx->pc = 0x1074e8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x1074ec: 0x550b000e  bnel        $t0, $t3, . + 4 + (0xE << 2)
    ctx->pc = 0x1074ECu;
    {
        const bool branch_taken_0x1074ec = (GPR_U64(ctx, 8) != GPR_U64(ctx, 11));
        if (branch_taken_0x1074ec) {
            ctx->pc = 0x1074F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1074ECu;
            // 0x1074f0: 0x8d020004  lw          $v0, 0x4($t0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107528u;
            goto label_107528;
        }
    }
    ctx->pc = 0x1074F4u;
    // 0x1074f4: 0x24a40003  addiu       $a0, $a1, 0x3
    ctx->pc = 0x1074f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
    // 0x1074f8: 0x28a30000  slti        $v1, $a1, 0x0
    ctx->pc = 0x1074f8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1074fc: 0x83280b  movn        $a1, $a0, $v1
    ctx->pc = 0x1074fcu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 4));
    // 0x107500: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x107500u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x107504: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x107504u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x107508: 0x52083  sra         $a0, $a1, 2
    ctx->pc = 0x107508u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 5), 2));
    // 0x10750c: 0x821014  dsllv       $v0, $v0, $a0
    ctx->pc = 0x10750cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 4) & 0x3F));
    // 0x107510: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x107510u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x107514: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x107514u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x107518: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x107518u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x10751c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x10751Cu;
    {
        const bool branch_taken_0x10751c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10751Cu;
            // 0x107520: 0xace30004  sw          $v1, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10751c) {
            ctx->pc = 0x107558u;
            goto label_107558;
        }
    }
    ctx->pc = 0x107524u;
    // 0x107524: 0x0  nop
    ctx->pc = 0x107524u;
    // NOP
label_107528:
    // 0x107528: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x107528u;
    {
        const bool branch_taken_0x107528 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10752Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107528u;
            // 0x10752c: 0x2403fffc  addiu       $v1, $zero, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107528) {
            ctx->pc = 0x10753Cu;
            goto label_10753c;
        }
    }
    ctx->pc = 0x107530u;
label_107530:
    // 0x107530: 0x510b0009  beql        $t0, $t3, . + 4 + (0x9 << 2)
    ctx->pc = 0x107530u;
    {
        const bool branch_taken_0x107530 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 11));
        if (branch_taken_0x107530) {
            ctx->pc = 0x107534u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107530u;
            // 0x107534: 0x8d0b000c  lw          $t3, 0xC($t0) (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107558u;
            goto label_107558;
        }
    }
    ctx->pc = 0x107538u;
    // 0x107538: 0x8d020004  lw          $v0, 0x4($t0)
    ctx->pc = 0x107538u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
label_10753c:
    // 0x10753c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10753cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x107540: 0xc2102b  sltu        $v0, $a2, $v0
    ctx->pc = 0x107540u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x107544: 0x0  nop
    ctx->pc = 0x107544u;
    // NOP
    // 0x107548: 0x0  nop
    ctx->pc = 0x107548u;
    // NOP
    // 0x10754c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10754Cu;
    {
        const bool branch_taken_0x10754c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10754c) {
            ctx->pc = 0x107550u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10754Cu;
            // 0x107550: 0x8d080008  lw          $t0, 0x8($t0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107530u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107530;
        }
    }
    ctx->pc = 0x107554u;
    // 0x107554: 0x8d0b000c  lw          $t3, 0xC($t0)
    ctx->pc = 0x107554u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
label_107558:
    // 0x107558: 0xae0b000c  sw          $t3, 0xC($s0)
    ctx->pc = 0x107558u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 11));
    // 0x10755c: 0xae080008  sw          $t0, 0x8($s0)
    ctx->pc = 0x10755cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 8));
label_107560:
    // 0x107560: 0xad700008  sw          $s0, 0x8($t3)
    ctx->pc = 0x107560u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 8), GPR_U32(ctx, 16));
    // 0x107564: 0xad10000c  sw          $s0, 0xC($t0)
    ctx->pc = 0x107564u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 16));
label_107568:
    // 0x107568: 0x29420000  slti        $v0, $t2, 0x0
    ctx->pc = 0x107568u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x10756c: 0x25450003  addiu       $a1, $t2, 0x3
    ctx->pc = 0x10756cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), 3));
    // 0x107570: 0x140202d  daddu       $a0, $t2, $zero
    ctx->pc = 0x107570u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107574: 0x3c140021  lui         $s4, 0x21
    ctx->pc = 0x107574u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
    // 0x107578: 0xa2200b  movn        $a0, $a1, $v0
    ctx->pc = 0x107578u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 5));
    // 0x10757c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10757cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x107580: 0x26839800  addiu       $v1, $s4, -0x6800
    ctx->pc = 0x107580u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), 4294940672));
    // 0x107584: 0x42083  sra         $a0, $a0, 2
    ctx->pc = 0x107584u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 2));
    // 0x107588: 0x9c660004  lwu         $a2, 0x4($v1)
    ctx->pc = 0x107588u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x10758c: 0x824814  dsllv       $t1, $v0, $a0
    ctx->pc = 0x10758cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) << (GPR_U32(ctx, 4) & 0x3F));
    // 0x107590: 0xc9182b  sltu        $v1, $a2, $t1
    ctx->pc = 0x107590u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x107594: 0x54600061  bnel        $v1, $zero, . + 4 + (0x61 << 2)
    ctx->pc = 0x107594u;
    {
        const bool branch_taken_0x107594 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x107594) {
            ctx->pc = 0x107598u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107594u;
            // 0x107598: 0x26849800  addiu       $a0, $s4, -0x6800 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294940672));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10771Cu;
            goto label_10771c;
        }
    }
    ctx->pc = 0x10759Cu;
    // 0x10759c: 0x1261024  and         $v0, $t1, $a2
    ctx->pc = 0x10759cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) & GPR_U64(ctx, 6));
    // 0x1075a0: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1075A0u;
    {
        const bool branch_taken_0x1075a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1075A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1075A0u;
            // 0x1075a4: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1075a0) {
            ctx->pc = 0x1075E8u;
            goto label_1075e8;
        }
    }
    ctx->pc = 0x1075A8u;
    // 0x1075a8: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1075a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1075ac: 0x94878  dsll        $t1, $t1, 1
    ctx->pc = 0x1075acu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 1);
    // 0x1075b0: 0x1421024  and         $v0, $t2, $v0
    ctx->pc = 0x1075b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) & GPR_U64(ctx, 2));
    // 0x1075b4: 0x1261824  and         $v1, $t1, $a2
    ctx->pc = 0x1075b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) & GPR_U64(ctx, 6));
    // 0x1075b8: 0x1460000a  bnez        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1075B8u;
    {
        const bool branch_taken_0x1075b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1075BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1075B8u;
            // 0x1075bc: 0x244a0004  addiu       $t2, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1075b8) {
            ctx->pc = 0x1075E4u;
            goto label_1075e4;
        }
    }
    ctx->pc = 0x1075C0u;
    // 0x1075c0: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x1075c0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1075c4: 0x0  nop
    ctx->pc = 0x1075c4u;
    // NOP
label_1075c8:
    // 0x1075c8: 0x94878  dsll        $t1, $t1, 1
    ctx->pc = 0x1075c8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 1);
    // 0x1075cc: 0x1231024  and         $v0, $t1, $v1
    ctx->pc = 0x1075ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) & GPR_U64(ctx, 3));
    // 0x1075d0: 0x0  nop
    ctx->pc = 0x1075d0u;
    // NOP
    // 0x1075d4: 0x0  nop
    ctx->pc = 0x1075d4u;
    // NOP
    // 0x1075d8: 0x0  nop
    ctx->pc = 0x1075d8u;
    // NOP
    // 0x1075dc: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1075DCu;
    {
        const bool branch_taken_0x1075dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1075E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1075DCu;
            // 0x1075e0: 0x254a0004  addiu       $t2, $t2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1075dc) {
            ctx->pc = 0x1075C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1075c8;
        }
    }
    ctx->pc = 0x1075E4u;
label_1075e4:
    // 0x1075e4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1075e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
label_1075e8:
    // 0x1075e8: 0x244d9800  addiu       $t5, $v0, -0x6800
    ctx->pc = 0x1075e8u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 2), 4294940672));
    // 0x1075ec: 0x40702d  daddu       $t6, $v0, $zero
    ctx->pc = 0x1075ecu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1075f0: 0x1a0902d  daddu       $s2, $t5, $zero
    ctx->pc = 0x1075f0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1075f4: 0xa10c0  sll         $v0, $t2, 3
    ctx->pc = 0x1075f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
label_1075f8:
    // 0x1075f8: 0x140582d  daddu       $t3, $t2, $zero
    ctx->pc = 0x1075f8u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1075fc: 0x4d2021  addu        $a0, $v0, $t5
    ctx->pc = 0x1075fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 13)));
    // 0x107600: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x107600u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107604: 0x8cb0000c  lw          $s0, 0xC($a1)
    ctx->pc = 0x107604u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
label_107608:
    // 0x107608: 0x12050016  beq         $s0, $a1, . + 4 + (0x16 << 2)
    ctx->pc = 0x107608u;
    {
        const bool branch_taken_0x107608 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 5));
        ctx->pc = 0x10760Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107608u;
            // 0x10760c: 0x2942003f  slti        $v0, $t2, 0x3F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)63) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x107608) {
            ctx->pc = 0x107664u;
            goto label_107664;
        }
    }
    ctx->pc = 0x107610u;
    // 0x107610: 0x240cfffc  addiu       $t4, $zero, -0x4
    ctx->pc = 0x107610u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x107614: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x107614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_107618:
    // 0x107618: 0x4c3024  and         $a2, $v0, $t4
    ctx->pc = 0x107618u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & GPR_U64(ctx, 12));
    // 0x10761c: 0x2261823  subu        $v1, $s1, $a2
    ctx->pc = 0x10761cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 6)));
    // 0x107620: 0xd11023  subu        $v0, $a2, $s1
    ctx->pc = 0x107620u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x107624: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x107624u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x107628: 0x2383c  dsll32      $a3, $v0, 0
    ctx->pc = 0x107628u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10762c: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x10762cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x107630: 0xd1102b  sltu        $v0, $a2, $s1
    ctx->pc = 0x107630u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x107634: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x107634u;
    {
        const bool branch_taken_0x107634 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107634u;
            // 0x107638: 0x3402f  dsubu       $t0, $zero, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) - GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107634) {
            ctx->pc = 0x107640u;
            goto label_107640;
        }
    }
    ctx->pc = 0x10763Cu;
    // 0x10763c: 0x7403e  dsrl32      $t0, $a3, 0
    ctx->pc = 0x10763cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 7) >> (32 + 0));
label_107640:
    // 0x107640: 0x29020010  slti        $v0, $t0, 0x10
    ctx->pc = 0x107640u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x107644: 0x50400078  beql        $v0, $zero, . + 4 + (0x78 << 2)
    ctx->pc = 0x107644u;
    {
        const bool branch_taken_0x107644 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x107644) {
            ctx->pc = 0x107648u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107644u;
            // 0x107648: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107828u;
            goto label_107828;
        }
    }
    ctx->pc = 0x10764Cu;
    // 0x10764c: 0x503008c  bgezl       $t0, . + 4 + (0x8C << 2)
    ctx->pc = 0x10764Cu;
    {
        const bool branch_taken_0x10764c = (GPR_S64(ctx, 8) >= 0);
        if (branch_taken_0x10764c) {
            ctx->pc = 0x107650u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10764Cu;
            // 0x107650: 0x2061821  addu        $v1, $s0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107880u;
            goto label_107880;
        }
    }
    ctx->pc = 0x107654u;
    // 0x107654: 0x8e10000c  lw          $s0, 0xC($s0)
    ctx->pc = 0x107654u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x107658: 0x5605ffef  bnel        $s0, $a1, . + 4 + (-0x11 << 2)
    ctx->pc = 0x107658u;
    {
        const bool branch_taken_0x107658 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 5));
        if (branch_taken_0x107658) {
            ctx->pc = 0x10765Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x107658u;
            // 0x10765c: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107618u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107618;
        }
    }
    ctx->pc = 0x107660u;
    // 0x107660: 0x2942003f  slti        $v0, $t2, 0x3F
    ctx->pc = 0x107660u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)63) ? 1 : 0);
label_107664:
    // 0x107664: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x107664u;
    {
        const bool branch_taken_0x107664 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107664u;
            // 0x107668: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107664) {
            ctx->pc = 0x107674u;
            goto label_107674;
        }
    }
    ctx->pc = 0x10766Cu;
    // 0x10766c: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x10766cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x107670: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x107670u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
label_107674:
    // 0x107674: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x107674u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x107678: 0x31420003  andi        $v0, $t2, 0x3
    ctx->pc = 0x107678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)3);
    // 0x10767c: 0x5440ffe2  bnel        $v0, $zero, . + 4 + (-0x1E << 2)
    ctx->pc = 0x10767Cu;
    {
        const bool branch_taken_0x10767c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10767c) {
            ctx->pc = 0x107680u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10767Cu;
            // 0x107680: 0x8cb0000c  lw          $s0, 0xC($a1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x107608u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107608;
        }
    }
    ctx->pc = 0x107684u;
    // 0x107684: 0x9103c  dsll32      $v0, $t1, 0
    ctx->pc = 0x107684u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) << (32 + 0));
    // 0x107688: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x107688u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10768c: 0x25c59800  addiu       $a1, $t6, -0x6800
    ctx->pc = 0x10768cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 14), 4294940672));
    // 0x107690: 0x21827  nor         $v1, $zero, $v0
    ctx->pc = 0x107690u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x107694: 0x31620003  andi        $v0, $t3, 0x3
    ctx->pc = 0x107694u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)3);
label_107698:
    // 0x107698: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x107698u;
    {
        const bool branch_taken_0x107698 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10769Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107698u;
            // 0x10769c: 0x256bffff  addiu       $t3, $t3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107698) {
            ctx->pc = 0x1076B0u;
            goto label_1076b0;
        }
    }
    ctx->pc = 0x1076A0u;
    // 0x1076a0: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1076a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1076a4: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1076a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1076a8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1076A8u;
    {
        const bool branch_taken_0x1076a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1076ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1076A8u;
            // 0x1076ac: 0xaca20004  sw          $v0, 0x4($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1076a8) {
            ctx->pc = 0x1076C4u;
            goto label_1076c4;
        }
    }
    ctx->pc = 0x1076B0u;
label_1076b0:
    // 0x1076b0: 0x2484fff8  addiu       $a0, $a0, -0x8
    ctx->pc = 0x1076b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967288));
    // 0x1076b4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1076b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1076b8: 0x0  nop
    ctx->pc = 0x1076b8u;
    // NOP
    // 0x1076bc: 0x1044fff6  beq         $v0, $a0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1076BCu;
    {
        const bool branch_taken_0x1076bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x1076C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1076BCu;
            // 0x1076c0: 0x31620003  andi        $v0, $t3, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1076bc) {
            ctx->pc = 0x107698u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107698;
        }
    }
    ctx->pc = 0x1076C4u;
label_1076c4:
    // 0x1076c4: 0x9da30004  lwu         $v1, 0x4($t5)
    ctx->pc = 0x1076c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 13), 4)));
    // 0x1076c8: 0x94878  dsll        $t1, $t1, 1
    ctx->pc = 0x1076c8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 1);
    // 0x1076cc: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x1076ccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x1076d0: 0x54400012  bnel        $v0, $zero, . + 4 + (0x12 << 2)
    ctx->pc = 0x1076D0u;
    {
        const bool branch_taken_0x1076d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1076d0) {
            ctx->pc = 0x1076D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1076D0u;
            // 0x1076d4: 0x26849800  addiu       $a0, $s4, -0x6800 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294940672));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10771Cu;
            goto label_10771c;
        }
    }
    ctx->pc = 0x1076D8u;
    // 0x1076d8: 0x1120000f  beqz        $t1, . + 4 + (0xF << 2)
    ctx->pc = 0x1076D8u;
    {
        const bool branch_taken_0x1076d8 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x1076DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1076D8u;
            // 0x1076dc: 0x1231024  and         $v0, $t1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1076d8) {
            ctx->pc = 0x107718u;
            goto label_107718;
        }
    }
    ctx->pc = 0x1076E0u;
    // 0x1076e0: 0x1440ffc5  bnez        $v0, . + 4 + (-0x3B << 2)
    ctx->pc = 0x1076E0u;
    {
        const bool branch_taken_0x1076e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1076E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1076E0u;
            // 0x1076e4: 0xa10c0  sll         $v0, $t2, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1076e0) {
            ctx->pc = 0x1075F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1075f8;
        }
    }
    ctx->pc = 0x1076E8u;
    // 0x1076e8: 0x9e430004  lwu         $v1, 0x4($s2)
    ctx->pc = 0x1076e8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1076ec: 0x0  nop
    ctx->pc = 0x1076ecu;
    // NOP
label_1076f0:
    // 0x1076f0: 0x94878  dsll        $t1, $t1, 1
    ctx->pc = 0x1076f0u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 1);
    // 0x1076f4: 0x1231024  and         $v0, $t1, $v1
    ctx->pc = 0x1076f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) & GPR_U64(ctx, 3));
    // 0x1076f8: 0x0  nop
    ctx->pc = 0x1076f8u;
    // NOP
    // 0x1076fc: 0x0  nop
    ctx->pc = 0x1076fcu;
    // NOP
    // 0x107700: 0x0  nop
    ctx->pc = 0x107700u;
    // NOP
    // 0x107704: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x107704u;
    {
        const bool branch_taken_0x107704 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107704u;
            // 0x107708: 0x254a0004  addiu       $t2, $t2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107704) {
            ctx->pc = 0x1076F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1076f0;
        }
    }
    ctx->pc = 0x10770Cu;
    // 0x10770c: 0x1000ffba  b           . + 4 + (-0x46 << 2)
    ctx->pc = 0x10770Cu;
    {
        const bool branch_taken_0x10770c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10770Cu;
            // 0x107710: 0xa10c0  sll         $v0, $t2, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10770c) {
            ctx->pc = 0x1075F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1075f8;
        }
    }
    ctx->pc = 0x107714u;
    // 0x107714: 0x0  nop
    ctx->pc = 0x107714u;
    // NOP
label_107718:
    // 0x107718: 0x26849800  addiu       $a0, $s4, -0x6800
    ctx->pc = 0x107718u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294940672));
label_10771c:
    // 0x10771c: 0x2405fffc  addiu       $a1, $zero, -0x4
    ctx->pc = 0x10771cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x107720: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x107720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x107724: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x107724u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x107728: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x107728u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x10772c: 0x71102b  sltu        $v0, $v1, $s1
    ctx->pc = 0x10772cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x107730: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x107730u;
    {
        const bool branch_taken_0x107730 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107730u;
            // 0x107734: 0x711023  subu        $v0, $v1, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107730) {
            ctx->pc = 0x107750u;
            goto label_107750;
        }
    }
    ctx->pc = 0x107738u;
    // 0x107738: 0x2231023  subu        $v0, $s1, $v1
    ctx->pc = 0x107738u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x10773c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10773cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x107740: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x107740u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x107744: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x107744u;
    {
        const bool branch_taken_0x107744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107744u;
            // 0x107748: 0x2402f  dsubu       $t0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107744) {
            ctx->pc = 0x107758u;
            goto label_107758;
        }
    }
    ctx->pc = 0x10774Cu;
    // 0x10774c: 0x0  nop
    ctx->pc = 0x10774cu;
    // NOP
label_107750:
    // 0x107750: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x107750u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x107754: 0x2403e  dsrl32      $t0, $v0, 0
    ctx->pc = 0x107754u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) >> (32 + 0));
label_107758:
    // 0x107758: 0x26909800  addiu       $s0, $s4, -0x6800
    ctx->pc = 0x107758u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 4294940672));
    // 0x10775c: 0x2412fffc  addiu       $s2, $zero, -0x4
    ctx->pc = 0x10775cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x107760: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x107760u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x107764: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x107764u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x107768: 0x521024  and         $v0, $v0, $s2
    ctx->pc = 0x107768u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 18));
    // 0x10776c: 0x51102b  sltu        $v0, $v0, $s1
    ctx->pc = 0x10776cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x107770: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x107770u;
    {
        const bool branch_taken_0x107770 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107770u;
            // 0x107774: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107770) {
            ctx->pc = 0x107788u;
            goto label_107788;
        }
    }
    ctx->pc = 0x107778u;
    // 0x107778: 0x29020010  slti        $v0, $t0, 0x10
    ctx->pc = 0x107778u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x10777c: 0x1040004a  beqz        $v0, . + 4 + (0x4A << 2)
    ctx->pc = 0x10777Cu;
    {
        const bool branch_taken_0x10777c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x107780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10777Cu;
            // 0x107780: 0x26869800  addiu       $a2, $s4, -0x6800 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), 4294940672));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10777c) {
            ctx->pc = 0x1078A8u;
            goto label_1078a8;
        }
    }
    ctx->pc = 0x107784u;
    // 0x107784: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x107784u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_107788:
    // 0x107788: 0xc041be0  jal         func_106F80
    ctx->pc = 0x107788u;
    SET_GPR_U32(ctx, 31, 0x107790u);
    ctx->pc = 0x10778Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x107788u;
            // 0x10778c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106F80u;
    if (runtime->hasFunction(0x106F80u)) {
        auto targetFn = runtime->lookupFunction(0x106F80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107790u; }
        if (ctx->pc != 0x107790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106F80_0x106f80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x107790u; }
        if (ctx->pc != 0x107790u) { return; }
    }
    ctx->pc = 0x107790u;
label_107790:
    // 0x107790: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x107790u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x107794: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x107794u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x107798: 0x721824  and         $v1, $v1, $s2
    ctx->pc = 0x107798u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 18));
    // 0x10779c: 0x71102b  sltu        $v0, $v1, $s1
    ctx->pc = 0x10779cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x1077a0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1077A0u;
    {
        const bool branch_taken_0x1077a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1077A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1077A0u;
            // 0x1077a4: 0x711023  subu        $v0, $v1, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1077a0) {
            ctx->pc = 0x1077C0u;
            goto label_1077c0;
        }
    }
    ctx->pc = 0x1077A8u;
    // 0x1077a8: 0x2231023  subu        $v0, $s1, $v1
    ctx->pc = 0x1077a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x1077ac: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1077acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1077b0: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1077b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1077b4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1077B4u;
    {
        const bool branch_taken_0x1077b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1077B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1077B4u;
            // 0x1077b8: 0x2402f  dsubu       $t0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1077b4) {
            ctx->pc = 0x1077C8u;
            goto label_1077c8;
        }
    }
    ctx->pc = 0x1077BCu;
    // 0x1077bc: 0x0  nop
    ctx->pc = 0x1077bcu;
    // NOP
label_1077c0:
    // 0x1077c0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1077c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1077c4: 0x2403e  dsrl32      $t0, $v0, 0
    ctx->pc = 0x1077c4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) >> (32 + 0));
label_1077c8:
    // 0x1077c8: 0x26849800  addiu       $a0, $s4, -0x6800
    ctx->pc = 0x1077c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294940672));
    // 0x1077cc: 0x2405fffc  addiu       $a1, $zero, -0x4
    ctx->pc = 0x1077ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1077d0: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1077d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1077d4: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1077d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1077d8: 0x451024  and         $v0, $v0, $a1
    ctx->pc = 0x1077d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 5));
    // 0x1077dc: 0x51102b  sltu        $v0, $v0, $s1
    ctx->pc = 0x1077dcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x1077e0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1077E0u;
    {
        const bool branch_taken_0x1077e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1077E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1077E0u;
            // 0x1077e4: 0x29020010  slti        $v0, $t0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)16) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1077e0) {
            ctx->pc = 0x1077F0u;
            goto label_1077f0;
        }
    }
    ctx->pc = 0x1077E8u;
    // 0x1077e8: 0x1040002f  beqz        $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x1077E8u;
    {
        const bool branch_taken_0x1077e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1077ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1077E8u;
            // 0x1077ec: 0x26869800  addiu       $a2, $s4, -0x6800 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), 4294940672));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1077e8) {
            ctx->pc = 0x1078A8u;
            goto label_1078a8;
        }
    }
    ctx->pc = 0x1077F0u;
label_1077f0:
    // 0x1077f0: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x1077F0u;
    SET_GPR_U32(ctx, 31, 0x1077F8u);
    ctx->pc = 0x1077F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1077F0u;
            // 0x1077f4: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1077F8u; }
        if (ctx->pc != 0x1077F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1077F8u; }
        if (ctx->pc != 0x1077F8u) { return; }
    }
    ctx->pc = 0x1077F8u;
label_1077f8:
    // 0x1077f8: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1077F8u;
    {
        const bool branch_taken_0x1077f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1077FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1077F8u;
            // 0x1077fc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1077f8) {
            ctx->pc = 0x1078E0u;
            goto label_1078e0;
        }
    }
    ctx->pc = 0x107800u;
label_107800:
    // 0x107800: 0x8e0b000c  lw          $t3, 0xC($s0)
    ctx->pc = 0x107800u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x107804: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x107804u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x107808: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x107808u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10780c: 0x8e080008  lw          $t0, 0x8($s0)
    ctx->pc = 0x10780cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x107810: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x107810u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x107814: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x107814u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x107818: 0xad0b000c  sw          $t3, 0xC($t0)
    ctx->pc = 0x107818u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 11));
    // 0x10781c: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x10781Cu;
    {
        const bool branch_taken_0x10781c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x107820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10781Cu;
            // 0x107820: 0xad680008  sw          $t0, 0x8($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 8), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10781c) {
            ctx->pc = 0x1078D4u;
            goto label_1078d4;
        }
    }
    ctx->pc = 0x107824u;
    // 0x107824: 0x0  nop
    ctx->pc = 0x107824u;
    // NOP
label_107828:
    // 0x107828: 0x8e0b000c  lw          $t3, 0xC($s0)
    ctx->pc = 0x107828u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10782c: 0x2114821  addu        $t1, $s0, $s1
    ctx->pc = 0x10782cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x107830: 0x8383c  dsll32      $a3, $t0, 0
    ctx->pc = 0x107830u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 8) << (32 + 0));
    // 0x107834: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x107834u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x107838: 0x1031825  or          $v1, $t0, $v1
    ctx->pc = 0x107838u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x10783c: 0x8e080008  lw          $t0, 0x8($s0)
    ctx->pc = 0x10783cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x107840: 0x25e59808  addiu       $a1, $t7, -0x67F8
    ctx->pc = 0x107840u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 15), 4294940680));
    // 0x107844: 0x36220001  ori         $v0, $s1, 0x1
    ctx->pc = 0x107844u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)1);
    // 0x107848: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x107848u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x10784c: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x10784cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x107850: 0x1273021  addu        $a2, $t1, $a3
    ctx->pc = 0x107850u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 7)));
    // 0x107854: 0xad0b000c  sw          $t3, 0xC($t0)
    ctx->pc = 0x107854u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 11));
    // 0x107858: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x107858u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10785c: 0xad680008  sw          $t0, 0x8($t3)
    ctx->pc = 0x10785cu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 8), GPR_U32(ctx, 8));
    // 0x107860: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x107860u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x107864: 0xaca9000c  sw          $t1, 0xC($a1)
    ctx->pc = 0x107864u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 9));
    // 0x107868: 0xaca90008  sw          $t1, 0x8($a1)
    ctx->pc = 0x107868u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 9));
    // 0x10786c: 0xad230004  sw          $v1, 0x4($t1)
    ctx->pc = 0x10786cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4), GPR_U32(ctx, 3));
    // 0x107870: 0xad250008  sw          $a1, 0x8($t1)
    ctx->pc = 0x107870u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 8), GPR_U32(ctx, 5));
    // 0x107874: 0xacc70000  sw          $a3, 0x0($a2)
    ctx->pc = 0x107874u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 7));
    // 0x107878: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x107878u;
    {
        const bool branch_taken_0x107878 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10787Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107878u;
            // 0x10787c: 0xad25000c  sw          $a1, 0xC($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 12), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107878) {
            ctx->pc = 0x1078D4u;
            goto label_1078d4;
        }
    }
    ctx->pc = 0x107880u;
label_107880:
    // 0x107880: 0x8e0b000c  lw          $t3, 0xC($s0)
    ctx->pc = 0x107880u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x107884: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x107884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x107888: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x107888u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10788c: 0x8e080008  lw          $t0, 0x8($s0)
    ctx->pc = 0x10788cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x107890: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x107890u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x107894: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x107894u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x107898: 0xad0b000c  sw          $t3, 0xC($t0)
    ctx->pc = 0x107898u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 11));
    // 0x10789c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x10789Cu;
    {
        const bool branch_taken_0x10789c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1078A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10789Cu;
            // 0x1078a0: 0xad680008  sw          $t0, 0x8($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 8), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10789c) {
            ctx->pc = 0x1078D4u;
            goto label_1078d4;
        }
    }
    ctx->pc = 0x1078A4u;
    // 0x1078a4: 0x0  nop
    ctx->pc = 0x1078a4u;
    // NOP
label_1078a8:
    // 0x1078a8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1078a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1078ac: 0x8cd00008  lw          $s0, 0x8($a2)
    ctx->pc = 0x1078acu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x1078b0: 0x1021025  or          $v0, $t0, $v0
    ctx->pc = 0x1078b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1078b4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1078b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1078b8: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1078b8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1078bc: 0x36230001  ori         $v1, $s1, 0x1
    ctx->pc = 0x1078bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)1);
    // 0x1078c0: 0x2112821  addu        $a1, $s0, $s1
    ctx->pc = 0x1078c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x1078c4: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1078c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1078c8: 0xacc50008  sw          $a1, 0x8($a2)
    ctx->pc = 0x1078c8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 5));
    // 0x1078cc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1078ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1078d0: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1078d0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
label_1078d4:
    // 0x1078d4: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x1078D4u;
    SET_GPR_U32(ctx, 31, 0x1078DCu);
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1078DCu; }
        if (ctx->pc != 0x1078DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1078DCu; }
        if (ctx->pc != 0x1078DCu) { return; }
    }
    ctx->pc = 0x1078DCu;
label_1078dc:
    // 0x1078dc: 0x26020008  addiu       $v0, $s0, 0x8
    ctx->pc = 0x1078dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
label_1078e0:
    // 0x1078e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1078e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1078e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1078e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1078e8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1078e8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1078ec: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1078ecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1078f0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1078f0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1078f4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1078f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1078f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1078F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1078FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1078F8u;
            // 0x1078fc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107210u: goto label_107210;
            case 0x107214u: goto label_107214;
            case 0x10721Cu: goto label_10721c;
            case 0x107278u: goto label_107278;
            case 0x107280u: goto label_107280;
            case 0x1072A0u: goto label_1072a0;
            case 0x1072C0u: goto label_1072c0;
            case 0x1072D8u: goto label_1072d8;
            case 0x1072E8u: goto label_1072e8;
            case 0x107308u: goto label_107308;
            case 0x107314u: goto label_107314;
            case 0x107348u: goto label_107348;
            case 0x10735Cu: goto label_10735c;
            case 0x107398u: goto label_107398;
            case 0x1073A0u: goto label_1073a0;
            case 0x1073F8u: goto label_1073f8;
            case 0x107420u: goto label_107420;
            case 0x107470u: goto label_107470;
            case 0x107490u: goto label_107490;
            case 0x1074B0u: goto label_1074b0;
            case 0x1074C8u: goto label_1074c8;
            case 0x1074D8u: goto label_1074d8;
            case 0x107528u: goto label_107528;
            case 0x107530u: goto label_107530;
            case 0x10753Cu: goto label_10753c;
            case 0x107558u: goto label_107558;
            case 0x107560u: goto label_107560;
            case 0x107568u: goto label_107568;
            case 0x1075C8u: goto label_1075c8;
            case 0x1075E4u: goto label_1075e4;
            case 0x1075E8u: goto label_1075e8;
            case 0x1075F8u: goto label_1075f8;
            case 0x107608u: goto label_107608;
            case 0x107618u: goto label_107618;
            case 0x107640u: goto label_107640;
            case 0x107664u: goto label_107664;
            case 0x107674u: goto label_107674;
            case 0x107698u: goto label_107698;
            case 0x1076B0u: goto label_1076b0;
            case 0x1076C4u: goto label_1076c4;
            case 0x1076F0u: goto label_1076f0;
            case 0x107718u: goto label_107718;
            case 0x10771Cu: goto label_10771c;
            case 0x107750u: goto label_107750;
            case 0x107758u: goto label_107758;
            case 0x107788u: goto label_107788;
            case 0x107790u: goto label_107790;
            case 0x1077C0u: goto label_1077c0;
            case 0x1077C8u: goto label_1077c8;
            case 0x1077F0u: goto label_1077f0;
            case 0x1077F8u: goto label_1077f8;
            case 0x107800u: goto label_107800;
            case 0x107828u: goto label_107828;
            case 0x107880u: goto label_107880;
            case 0x1078A8u: goto label_1078a8;
            case 0x1078D4u: goto label_1078d4;
            case 0x1078DCu: goto label_1078dc;
            case 0x1078E0u: goto label_1078e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107900u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
