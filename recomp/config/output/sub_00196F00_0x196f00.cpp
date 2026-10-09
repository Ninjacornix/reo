#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00196F00
// Address: 0x196f00 - 0x197468
void sub_00196F00_0x196f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00196F00_0x196f00");
#endif

    switch (ctx->pc) {
        case 0x1971b0u: goto label_1971b0;
        default: break;
    }

    ctx->pc = 0x196f00u;

    // 0x196f00: 0x308300ff  andi        $v1, $a0, 0xFF
    ctx->pc = 0x196f00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x196f04: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x196f04u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x196f08: 0x2404006d  addiu       $a0, $zero, 0x6D
    ctx->pc = 0x196f08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
    // 0x196f0c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x196f0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x196f10: 0x10640129  beq         $v1, $a0, . + 4 + (0x129 << 2)
    ctx->pc = 0x196F10u;
    {
        const bool branch_taken_0x196f10 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x196F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196F10u;
            // 0x196f14: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196f10) {
            ctx->pc = 0x1973B8u;
            goto label_1973b8;
        }
    }
    ctx->pc = 0x196F18u;
    // 0x196f18: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x196f18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x196f1c: 0x1064011e  beq         $v1, $a0, . + 4 + (0x11E << 2)
    ctx->pc = 0x196F1Cu;
    {
        const bool branch_taken_0x196f1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f1c) {
            ctx->pc = 0x197398u;
            goto label_197398;
        }
    }
    ctx->pc = 0x196F24u;
    // 0x196f24: 0x2404006b  addiu       $a0, $zero, 0x6B
    ctx->pc = 0x196f24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x196f28: 0x10640116  beq         $v1, $a0, . + 4 + (0x116 << 2)
    ctx->pc = 0x196F28u;
    {
        const bool branch_taken_0x196f28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f28) {
            ctx->pc = 0x197384u;
            goto label_197384;
        }
    }
    ctx->pc = 0x196F30u;
    // 0x196f30: 0x2404006a  addiu       $a0, $zero, 0x6A
    ctx->pc = 0x196f30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 106));
    // 0x196f34: 0x10640110  beq         $v1, $a0, . + 4 + (0x110 << 2)
    ctx->pc = 0x196F34u;
    {
        const bool branch_taken_0x196f34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f34) {
            ctx->pc = 0x197378u;
            goto label_197378;
        }
    }
    ctx->pc = 0x196F3Cu;
    // 0x196f3c: 0x24040069  addiu       $a0, $zero, 0x69
    ctx->pc = 0x196f3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 105));
    // 0x196f40: 0x1064010a  beq         $v1, $a0, . + 4 + (0x10A << 2)
    ctx->pc = 0x196F40u;
    {
        const bool branch_taken_0x196f40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f40) {
            ctx->pc = 0x19736Cu;
            goto label_19736c;
        }
    }
    ctx->pc = 0x196F48u;
    // 0x196f48: 0x24040068  addiu       $a0, $zero, 0x68
    ctx->pc = 0x196f48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    // 0x196f4c: 0x10640143  beq         $v1, $a0, . + 4 + (0x143 << 2)
    ctx->pc = 0x196F4Cu;
    {
        const bool branch_taken_0x196f4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f4c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x196F54u;
    // 0x196f54: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x196f54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x196f58: 0x106400fc  beq         $v1, $a0, . + 4 + (0xFC << 2)
    ctx->pc = 0x196F58u;
    {
        const bool branch_taken_0x196f58 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f58) {
            ctx->pc = 0x19734Cu;
            goto label_19734c;
        }
    }
    ctx->pc = 0x196F60u;
    // 0x196f60: 0x24040065  addiu       $a0, $zero, 0x65
    ctx->pc = 0x196f60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x196f64: 0x1064013d  beq         $v1, $a0, . + 4 + (0x13D << 2)
    ctx->pc = 0x196F64u;
    {
        const bool branch_taken_0x196f64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f64) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x196F6Cu;
    // 0x196f6c: 0x24040064  addiu       $a0, $zero, 0x64
    ctx->pc = 0x196f6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x196f70: 0x106400f1  beq         $v1, $a0, . + 4 + (0xF1 << 2)
    ctx->pc = 0x196F70u;
    {
        const bool branch_taken_0x196f70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f70) {
            ctx->pc = 0x197338u;
            goto label_197338;
        }
    }
    ctx->pc = 0x196F78u;
    // 0x196f78: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x196f78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x196f7c: 0x106400e9  beq         $v1, $a0, . + 4 + (0xE9 << 2)
    ctx->pc = 0x196F7Cu;
    {
        const bool branch_taken_0x196f7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f7c) {
            ctx->pc = 0x197324u;
            goto label_197324;
        }
    }
    ctx->pc = 0x196F84u;
    // 0x196f84: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x196f84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x196f88: 0x106400de  beq         $v1, $a0, . + 4 + (0xDE << 2)
    ctx->pc = 0x196F88u;
    {
        const bool branch_taken_0x196f88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f88) {
            ctx->pc = 0x197304u;
            goto label_197304;
        }
    }
    ctx->pc = 0x196F90u;
    // 0x196f90: 0x24040061  addiu       $a0, $zero, 0x61
    ctx->pc = 0x196f90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 97));
    // 0x196f94: 0x106400d3  beq         $v1, $a0, . + 4 + (0xD3 << 2)
    ctx->pc = 0x196F94u;
    {
        const bool branch_taken_0x196f94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f94) {
            ctx->pc = 0x1972E4u;
            goto label_1972e4;
        }
    }
    ctx->pc = 0x196F9Cu;
    // 0x196f9c: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x196f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x196fa0: 0x106400cd  beq         $v1, $a0, . + 4 + (0xCD << 2)
    ctx->pc = 0x196FA0u;
    {
        const bool branch_taken_0x196fa0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fa0) {
            ctx->pc = 0x1972D8u;
            goto label_1972d8;
        }
    }
    ctx->pc = 0x196FA8u;
    // 0x196fa8: 0x2404005f  addiu       $a0, $zero, 0x5F
    ctx->pc = 0x196fa8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x196fac: 0x106400a0  beq         $v1, $a0, . + 4 + (0xA0 << 2)
    ctx->pc = 0x196FACu;
    {
        const bool branch_taken_0x196fac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fac) {
            ctx->pc = 0x197230u;
            goto label_197230;
        }
    }
    ctx->pc = 0x196FB4u;
    // 0x196fb4: 0x2404005e  addiu       $a0, $zero, 0x5E
    ctx->pc = 0x196fb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x196fb8: 0x1064009a  beq         $v1, $a0, . + 4 + (0x9A << 2)
    ctx->pc = 0x196FB8u;
    {
        const bool branch_taken_0x196fb8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fb8) {
            ctx->pc = 0x197224u;
            goto label_197224;
        }
    }
    ctx->pc = 0x196FC0u;
    // 0x196fc0: 0x2404005d  addiu       $a0, $zero, 0x5D
    ctx->pc = 0x196fc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
    // 0x196fc4: 0x10640092  beq         $v1, $a0, . + 4 + (0x92 << 2)
    ctx->pc = 0x196FC4u;
    {
        const bool branch_taken_0x196fc4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fc4) {
            ctx->pc = 0x197210u;
            goto label_197210;
        }
    }
    ctx->pc = 0x196FCCu;
    // 0x196fcc: 0x2404005c  addiu       $a0, $zero, 0x5C
    ctx->pc = 0x196fccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x196fd0: 0x10640086  beq         $v1, $a0, . + 4 + (0x86 << 2)
    ctx->pc = 0x196FD0u;
    {
        const bool branch_taken_0x196fd0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x196FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196FD0u;
            // 0x196fd4: 0x2464ffa6  addiu       $a0, $v1, -0x5A (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967206));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196fd0) {
            ctx->pc = 0x1971ECu;
            goto label_1971ec;
        }
    }
    ctx->pc = 0x196FD8u;
    // 0x196fd8: 0x2404005b  addiu       $a0, $zero, 0x5B
    ctx->pc = 0x196fd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 91));
    // 0x196fdc: 0x10640082  beq         $v1, $a0, . + 4 + (0x82 << 2)
    ctx->pc = 0x196FDCu;
    {
        const bool branch_taken_0x196fdc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fdc) {
            ctx->pc = 0x1971E8u;
            goto label_1971e8;
        }
    }
    ctx->pc = 0x196FE4u;
    // 0x196fe4: 0x2404005a  addiu       $a0, $zero, 0x5A
    ctx->pc = 0x196fe4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x196fe8: 0x1064007f  beq         $v1, $a0, . + 4 + (0x7F << 2)
    ctx->pc = 0x196FE8u;
    {
        const bool branch_taken_0x196fe8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fe8) {
            ctx->pc = 0x1971E8u;
            goto label_1971e8;
        }
    }
    ctx->pc = 0x196FF0u;
    // 0x196ff0: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x196ff0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x196ff4: 0x10640070  beq         $v1, $a0, . + 4 + (0x70 << 2)
    ctx->pc = 0x196FF4u;
    {
        const bool branch_taken_0x196ff4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196ff4) {
            ctx->pc = 0x1971B8u;
            goto label_1971b8;
        }
    }
    ctx->pc = 0x196FFCu;
    // 0x196ffc: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x196ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x197000: 0x10640069  beq         $v1, $a0, . + 4 + (0x69 << 2)
    ctx->pc = 0x197000u;
    {
        const bool branch_taken_0x197000 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197000) {
            ctx->pc = 0x1971A8u;
            goto label_1971a8;
        }
    }
    ctx->pc = 0x197008u;
    // 0x197008: 0x24040013  addiu       $a0, $zero, 0x13
    ctx->pc = 0x197008u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x19700c: 0x10640113  beq         $v1, $a0, . + 4 + (0x113 << 2)
    ctx->pc = 0x19700Cu;
    {
        const bool branch_taken_0x19700c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x19700c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197014u;
    // 0x197014: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x197014u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x197018: 0x10640059  beq         $v1, $a0, . + 4 + (0x59 << 2)
    ctx->pc = 0x197018u;
    {
        const bool branch_taken_0x197018 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197018) {
            ctx->pc = 0x197180u;
            goto label_197180;
        }
    }
    ctx->pc = 0x197020u;
    // 0x197020: 0x24040011  addiu       $a0, $zero, 0x11
    ctx->pc = 0x197020u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x197024: 0x1064010d  beq         $v1, $a0, . + 4 + (0x10D << 2)
    ctx->pc = 0x197024u;
    {
        const bool branch_taken_0x197024 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197024) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19702Cu;
    // 0x19702c: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x19702cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x197030: 0x1064010a  beq         $v1, $a0, . + 4 + (0x10A << 2)
    ctx->pc = 0x197030u;
    {
        const bool branch_taken_0x197030 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197030) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197038u;
    // 0x197038: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x197038u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x19703c: 0x1064004d  beq         $v1, $a0, . + 4 + (0x4D << 2)
    ctx->pc = 0x19703Cu;
    {
        const bool branch_taken_0x19703c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x19703c) {
            ctx->pc = 0x197174u;
            goto label_197174;
        }
    }
    ctx->pc = 0x197044u;
    // 0x197044: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x197044u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x197048: 0x10640047  beq         $v1, $a0, . + 4 + (0x47 << 2)
    ctx->pc = 0x197048u;
    {
        const bool branch_taken_0x197048 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197048) {
            ctx->pc = 0x197168u;
            goto label_197168;
        }
    }
    ctx->pc = 0x197050u;
    // 0x197050: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x197050u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x197054: 0x10640040  beq         $v1, $a0, . + 4 + (0x40 << 2)
    ctx->pc = 0x197054u;
    {
        const bool branch_taken_0x197054 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197054) {
            ctx->pc = 0x197158u;
            goto label_197158;
        }
    }
    ctx->pc = 0x19705Cu;
    // 0x19705c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x19705cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x197060: 0x10640035  beq         $v1, $a0, . + 4 + (0x35 << 2)
    ctx->pc = 0x197060u;
    {
        const bool branch_taken_0x197060 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197060) {
            ctx->pc = 0x197138u;
            goto label_197138;
        }
    }
    ctx->pc = 0x197068u;
    // 0x197068: 0x2404000b  addiu       $a0, $zero, 0xB
    ctx->pc = 0x197068u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x19706c: 0x106400fb  beq         $v1, $a0, . + 4 + (0xFB << 2)
    ctx->pc = 0x19706Cu;
    {
        const bool branch_taken_0x19706c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x19706c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197074u;
    // 0x197074: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x197074u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x197078: 0x106400f8  beq         $v1, $a0, . + 4 + (0xF8 << 2)
    ctx->pc = 0x197078u;
    {
        const bool branch_taken_0x197078 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197078) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197080u;
    // 0x197080: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x197080u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x197084: 0x106400f5  beq         $v1, $a0, . + 4 + (0xF5 << 2)
    ctx->pc = 0x197084u;
    {
        const bool branch_taken_0x197084 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197084) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19708Cu;
    // 0x19708c: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x19708cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x197090: 0x106400f2  beq         $v1, $a0, . + 4 + (0xF2 << 2)
    ctx->pc = 0x197090u;
    {
        const bool branch_taken_0x197090 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197090) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197098u;
    // 0x197098: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x197098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x19709c: 0x1064001f  beq         $v1, $a0, . + 4 + (0x1F << 2)
    ctx->pc = 0x19709Cu;
    {
        const bool branch_taken_0x19709c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x19709c) {
            ctx->pc = 0x19711Cu;
            goto label_19711c;
        }
    }
    ctx->pc = 0x1970A4u;
    // 0x1970a4: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x1970a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1970a8: 0x1064001c  beq         $v1, $a0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1970A8u;
    {
        const bool branch_taken_0x1970a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970a8) {
            ctx->pc = 0x19711Cu;
            goto label_19711c;
        }
    }
    ctx->pc = 0x1970B0u;
    // 0x1970b0: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1970b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1970b4: 0x10640019  beq         $v1, $a0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1970B4u;
    {
        const bool branch_taken_0x1970b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970b4) {
            ctx->pc = 0x19711Cu;
            goto label_19711c;
        }
    }
    ctx->pc = 0x1970BCu;
    // 0x1970bc: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1970bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1970c0: 0x10640016  beq         $v1, $a0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1970C0u;
    {
        const bool branch_taken_0x1970c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970c0) {
            ctx->pc = 0x19711Cu;
            goto label_19711c;
        }
    }
    ctx->pc = 0x1970C8u;
    // 0x1970c8: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1970c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1970cc: 0x1064000f  beq         $v1, $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x1970CCu;
    {
        const bool branch_taken_0x1970cc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970cc) {
            ctx->pc = 0x19710Cu;
            goto label_19710c;
        }
    }
    ctx->pc = 0x1970D4u;
    // 0x1970d4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1970d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1970d8: 0x10640008  beq         $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1970D8u;
    {
        const bool branch_taken_0x1970d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970d8) {
            ctx->pc = 0x1970FCu;
            goto label_1970fc;
        }
    }
    ctx->pc = 0x1970E0u;
    // 0x1970e0: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1970e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1970e4: 0x106400dd  beq         $v1, $a0, . + 4 + (0xDD << 2)
    ctx->pc = 0x1970E4u;
    {
        const bool branch_taken_0x1970e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970e4) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1970ECu;
    // 0x1970ec: 0x106000db  beqz        $v1, . + 4 + (0xDB << 2)
    ctx->pc = 0x1970ECu;
    {
        const bool branch_taken_0x1970ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1970ec) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1970F4u;
    // 0x1970f4: 0x100000da  b           . + 4 + (0xDA << 2)
    ctx->pc = 0x1970F4u;
    {
        const bool branch_taken_0x1970f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1970F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1970F4u;
            // 0x1970f8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1970f4) {
            ctx->pc = 0x197460u;
            goto label_197460;
        }
    }
    ctx->pc = 0x1970FCu;
label_1970fc:
    // 0x1970fc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1970fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197100: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x197100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197104: 0x100000d5  b           . + 4 + (0xD5 << 2)
    ctx->pc = 0x197104u;
    {
        const bool branch_taken_0x197104 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197104u;
            // 0x197108: 0x30420f00  andi        $v0, $v0, 0xF00 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3840);
        ctx->in_delay_slot = false;
        if (branch_taken_0x197104) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19710Cu;
label_19710c:
    // 0x19710c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19710cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197110: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x197110u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197114: 0x100000d1  b           . + 4 + (0xD1 << 2)
    ctx->pc = 0x197114u;
    {
        const bool branch_taken_0x197114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197114u;
            // 0x197118: 0x3042001c  andi        $v0, $v0, 0x1C (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)28);
        ctx->in_delay_slot = false;
        if (branch_taken_0x197114) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19711Cu;
label_19711c:
    // 0x19711c: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x19711cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
    // 0x197120: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x197120u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x197124: 0x24424e60  addiu       $v0, $v0, 0x4E60
    ctx->pc = 0x197124u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20064));
    // 0x197128: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x197128u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x19712c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x19712cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x197130: 0x100000ca  b           . + 4 + (0xCA << 2)
    ctx->pc = 0x197130u;
    {
        const bool branch_taken_0x197130 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197130u;
            // 0x197134: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197130) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197138u;
label_197138:
    // 0x197138: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197138u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19713c: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x19713cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197140: 0x8c24fe70  lw          $a0, -0x190($at)
    ctx->pc = 0x197140u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197144: 0x30840080  andi        $a0, $a0, 0x80
    ctx->pc = 0x197144u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)128);
    // 0x197148: 0x148300c4  bne         $a0, $v1, . + 4 + (0xC4 << 2)
    ctx->pc = 0x197148u;
    {
        const bool branch_taken_0x197148 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x197148) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197150u;
    // 0x197150: 0x100000c2  b           . + 4 + (0xC2 << 2)
    ctx->pc = 0x197150u;
    {
        const bool branch_taken_0x197150 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197150u;
            // 0x197154: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197150) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197158u;
label_197158:
    // 0x197158: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197158u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19715c: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x19715cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x197160: 0x100000be  b           . + 4 + (0xBE << 2)
    ctx->pc = 0x197160u;
    {
        const bool branch_taken_0x197160 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197160u;
            // 0x197164: 0x30420c00  andi        $v0, $v0, 0xC00 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3072);
        ctx->in_delay_slot = false;
        if (branch_taken_0x197160) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197168u;
label_197168:
    // 0x197168: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197168u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19716c: 0x100000bb  b           . + 4 + (0xBB << 2)
    ctx->pc = 0x19716Cu;
    {
        const bool branch_taken_0x19716c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19716Cu;
            // 0x197170: 0x8c22fe30  lw          $v0, -0x1D0($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966832)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19716c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197174u;
label_197174:
    // 0x197174: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197174u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197178: 0x100000b8  b           . + 4 + (0xB8 << 2)
    ctx->pc = 0x197178u;
    {
        const bool branch_taken_0x197178 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19717Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197178u;
            // 0x19717c: 0x8c22fe38  lw          $v0, -0x1C8($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966840)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197178) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197180u;
label_197180:
    // 0x197180: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197180u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197184: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x197184u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x197188: 0x8c25fe70  lw          $a1, -0x190($at)
    ctx->pc = 0x197188u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x19718c: 0x34648000  ori         $a0, $v1, 0x8000
    ctx->pc = 0x19718cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32768);
    // 0x197190: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x197190u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x197194: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x197194u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x197198: 0x148300b0  bne         $a0, $v1, . + 4 + (0xB0 << 2)
    ctx->pc = 0x197198u;
    {
        const bool branch_taken_0x197198 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x197198) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971A0u;
    // 0x1971a0: 0x100000ae  b           . + 4 + (0xAE << 2)
    ctx->pc = 0x1971A0u;
    {
        const bool branch_taken_0x1971a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1971A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1971A0u;
            // 0x1971a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1971a0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971A8u;
label_1971a8:
    // 0x1971a8: 0xc065d20  jal         func_197480
    ctx->pc = 0x1971A8u;
    SET_GPR_U32(ctx, 31, 0x1971B0u);
    ctx->pc = 0x197480u;
    if (runtime->hasFunction(0x197480u)) {
        auto targetFn = runtime->lookupFunction(0x197480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1971B0u; }
        if (ctx->pc != 0x1971B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197480_0x197480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1971B0u; }
        if (ctx->pc != 0x1971B0u) { return; }
    }
    ctx->pc = 0x1971B0u;
label_1971b0:
    // 0x1971b0: 0x100000aa  b           . + 4 + (0xAA << 2)
    ctx->pc = 0x1971B0u;
    {
        const bool branch_taken_0x1971b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1971b0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971B8u;
label_1971b8:
    // 0x1971b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1971b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1971bc: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x1971bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1971c0: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x1971c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x1971c4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1971C4u;
    {
        const bool branch_taken_0x1971c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1971C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1971C4u;
            // 0x1971c8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1971c4) {
            ctx->pc = 0x1971D8u;
            goto label_1971d8;
        }
    }
    ctx->pc = 0x1971CCu;
    // 0x1971cc: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x1971CCu;
    {
        const bool branch_taken_0x1971cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1971D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1971CCu;
            // 0x1971d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1971cc) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971D4u;
    // 0x1971d4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1971d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1971d8:
    // 0x1971d8: 0x144300a0  bne         $v0, $v1, . + 4 + (0xA0 << 2)
    ctx->pc = 0x1971D8u;
    {
        const bool branch_taken_0x1971d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1971d8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971E0u;
    // 0x1971e0: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1971E0u;
    {
        const bool branch_taken_0x1971e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1971E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1971E0u;
            // 0x1971e4: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1971e0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971E8u;
label_1971e8:
    // 0x1971e8: 0x2464ffa6  addiu       $a0, $v1, -0x5A
    ctx->pc = 0x1971e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967206));
label_1971ec:
    // 0x1971ec: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1971ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1971f0: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1971f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1971f4: 0x24424200  addiu       $v0, $v0, 0x4200
    ctx->pc = 0x1971f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16896));
    // 0x1971f8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1971f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1971fc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1971fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x197200: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x197200u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x197204: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x197204u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x197208: 0x10000094  b           . + 4 + (0x94 << 2)
    ctx->pc = 0x197208u;
    {
        const bool branch_taken_0x197208 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19720Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197208u;
            // 0x19720c: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197208) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197210u;
label_197210:
    // 0x197210: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197210u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197214: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x197214u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x197218: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x197218u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x19721c: 0x1000008f  b           . + 4 + (0x8F << 2)
    ctx->pc = 0x19721Cu;
    {
        const bool branch_taken_0x19721c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19721Cu;
            // 0x197220: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19721c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197224u;
label_197224:
    // 0x197224: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197224u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197228: 0x1000008c  b           . + 4 + (0x8C << 2)
    ctx->pc = 0x197228u;
    {
        const bool branch_taken_0x197228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19722Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197228u;
            // 0x19722c: 0x9022fe68  lbu         $v0, -0x198($at) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294966888)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197228) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197230u;
label_197230:
    // 0x197230: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197230u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197234: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x197234u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x197238: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x197238u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x19723c: 0x832024  and         $a0, $a0, $v1
    ctx->pc = 0x19723cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x197240: 0x10830023  beq         $a0, $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x197240u;
    {
        const bool branch_taken_0x197240 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197240) {
            ctx->pc = 0x1972D0u;
            goto label_1972d0;
        }
    }
    ctx->pc = 0x197248u;
    // 0x197248: 0x3c030030  lui         $v1, 0x30
    ctx->pc = 0x197248u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)48 << 16));
    // 0x19724c: 0x1083001e  beq         $a0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x19724Cu;
    {
        const bool branch_taken_0x19724c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x19724c) {
            ctx->pc = 0x1972C8u;
            goto label_1972c8;
        }
    }
    ctx->pc = 0x197254u;
    // 0x197254: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x197254u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x197258: 0x10830019  beq         $a0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x197258u;
    {
        const bool branch_taken_0x197258 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197258) {
            ctx->pc = 0x1972C0u;
            goto label_1972c0;
        }
    }
    ctx->pc = 0x197260u;
    // 0x197260: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x197260u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x197264: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x197264u;
    {
        const bool branch_taken_0x197264 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197264) {
            ctx->pc = 0x1972B8u;
            goto label_1972b8;
        }
    }
    ctx->pc = 0x19726Cu;
    // 0x19726c: 0x3c030018  lui         $v1, 0x18
    ctx->pc = 0x19726cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)24 << 16));
    // 0x197270: 0x1083000f  beq         $a0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x197270u;
    {
        const bool branch_taken_0x197270 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197270) {
            ctx->pc = 0x1972B0u;
            goto label_1972b0;
        }
    }
    ctx->pc = 0x197278u;
    // 0x197278: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x197278u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
    // 0x19727c: 0x1083000a  beq         $a0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x19727Cu;
    {
        const bool branch_taken_0x19727c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x19727c) {
            ctx->pc = 0x1972A8u;
            goto label_1972a8;
        }
    }
    ctx->pc = 0x197284u;
    // 0x197284: 0x3c030008  lui         $v1, 0x8
    ctx->pc = 0x197284u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8 << 16));
    // 0x197288: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x197288u;
    {
        const bool branch_taken_0x197288 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197288) {
            ctx->pc = 0x1972A0u;
            goto label_1972a0;
        }
    }
    ctx->pc = 0x197290u;
    // 0x197290: 0x10800072  beqz        $a0, . + 4 + (0x72 << 2)
    ctx->pc = 0x197290u;
    {
        const bool branch_taken_0x197290 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x197290) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197298u;
    // 0x197298: 0x10000070  b           . + 4 + (0x70 << 2)
    ctx->pc = 0x197298u;
    {
        const bool branch_taken_0x197298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197298) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972A0u;
label_1972a0:
    // 0x1972a0: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x1972A0u;
    {
        const bool branch_taken_0x1972a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972A0u;
            // 0x1972a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972a0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972A8u;
label_1972a8:
    // 0x1972a8: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1972A8u;
    {
        const bool branch_taken_0x1972a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972A8u;
            // 0x1972ac: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972a8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972B0u;
label_1972b0:
    // 0x1972b0: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x1972B0u;
    {
        const bool branch_taken_0x1972b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972B0u;
            // 0x1972b4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972b0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972B8u;
label_1972b8:
    // 0x1972b8: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x1972B8u;
    {
        const bool branch_taken_0x1972b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972B8u;
            // 0x1972bc: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972b8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972C0u;
label_1972c0:
    // 0x1972c0: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x1972C0u;
    {
        const bool branch_taken_0x1972c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972C0u;
            // 0x1972c4: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972c0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972C8u;
label_1972c8:
    // 0x1972c8: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x1972C8u;
    {
        const bool branch_taken_0x1972c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972C8u;
            // 0x1972cc: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972c8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972D0u;
label_1972d0:
    // 0x1972d0: 0x10000062  b           . + 4 + (0x62 << 2)
    ctx->pc = 0x1972D0u;
    {
        const bool branch_taken_0x1972d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972D0u;
            // 0x1972d4: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972d0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972D8u;
label_1972d8:
    // 0x1972d8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1972d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1972dc: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x1972DCu;
    {
        const bool branch_taken_0x1972dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972DCu;
            // 0x1972e0: 0x8c22fe20  lw          $v0, -0x1E0($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966816)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972dc) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972E4u;
label_1972e4:
    // 0x1972e4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1972e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1972e8: 0x3c040100  lui         $a0, 0x100
    ctx->pc = 0x1972e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
    // 0x1972ec: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x1972ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1972f0: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x1972f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1972f4: 0x14640059  bne         $v1, $a0, . + 4 + (0x59 << 2)
    ctx->pc = 0x1972F4u;
    {
        const bool branch_taken_0x1972f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1972f4) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972FCu;
    // 0x1972fc: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1972FCu;
    {
        const bool branch_taken_0x1972fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972FCu;
            // 0x197300: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972fc) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197304u;
label_197304:
    // 0x197304: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197304u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197308: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x197308u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x19730c: 0x8c24fe70  lw          $a0, -0x190($at)
    ctx->pc = 0x19730cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197310: 0x30844000  andi        $a0, $a0, 0x4000
    ctx->pc = 0x197310u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)16384);
    // 0x197314: 0x14830051  bne         $a0, $v1, . + 4 + (0x51 << 2)
    ctx->pc = 0x197314u;
    {
        const bool branch_taken_0x197314 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x197314) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19731Cu;
    // 0x19731c: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x19731Cu;
    {
        const bool branch_taken_0x19731c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19731Cu;
            // 0x197320: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19731c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197324u;
label_197324:
    // 0x197324: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197324u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197328: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x197328u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x19732c: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x19732cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x197330: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x197330u;
    {
        const bool branch_taken_0x197330 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197330u;
            // 0x197334: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197330) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197338u;
label_197338:
    // 0x197338: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197338u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19733c: 0x3c020006  lui         $v0, 0x6
    ctx->pc = 0x19733cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)6 << 16));
    // 0x197340: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x197340u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x197344: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x197344u;
    {
        const bool branch_taken_0x197344 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197344u;
            // 0x197348: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197344) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19734Cu;
label_19734c:
    // 0x19734c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19734cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197350: 0x3c040002  lui         $a0, 0x2
    ctx->pc = 0x197350u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)2 << 16));
    // 0x197354: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x197354u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197358: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x197358u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x19735c: 0x1464003f  bne         $v1, $a0, . + 4 + (0x3F << 2)
    ctx->pc = 0x19735Cu;
    {
        const bool branch_taken_0x19735c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x19735c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197364u;
    // 0x197364: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x197364u;
    {
        const bool branch_taken_0x197364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197364u;
            // 0x197368: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197364) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19736Cu;
label_19736c:
    // 0x19736c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19736cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x197370: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x197370u;
    {
        const bool branch_taken_0x197370 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197370u;
            // 0x197374: 0x8c224e70  lw          $v0, 0x4E70($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20080)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197370) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197378u;
label_197378:
    // 0x197378: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x197378u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19737c: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x19737Cu;
    {
        const bool branch_taken_0x19737c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19737Cu;
            // 0x197380: 0x8c224e68  lw          $v0, 0x4E68($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20072)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19737c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197384u;
label_197384:
    // 0x197384: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197384u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197388: 0x3c0200c0  lui         $v0, 0xC0
    ctx->pc = 0x197388u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)192 << 16));
    // 0x19738c: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x19738cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x197390: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x197390u;
    {
        const bool branch_taken_0x197390 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197390u;
            // 0x197394: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197390) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197398u;
label_197398:
    // 0x197398: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197398u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19739c: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x19739cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1973a0: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x1973a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1973a4: 0x30848000  andi        $a0, $a0, 0x8000
    ctx->pc = 0x1973a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x1973a8: 0x1483002c  bne         $a0, $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x1973A8u;
    {
        const bool branch_taken_0x1973a8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1973a8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1973B0u;
    // 0x1973b0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1973B0u;
    {
        const bool branch_taken_0x1973b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1973B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1973B0u;
            // 0x1973b4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1973b0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1973B8u;
label_1973b8:
    // 0x1973b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1973b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1973bc: 0x24037000  addiu       $v1, $zero, 0x7000
    ctx->pc = 0x1973bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 28672));
    // 0x1973c0: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x1973c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1973c4: 0x30847000  andi        $a0, $a0, 0x7000
    ctx->pc = 0x1973c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)28672);
    // 0x1973c8: 0x10830023  beq         $a0, $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1973C8u;
    {
        const bool branch_taken_0x1973c8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973c8) {
            ctx->pc = 0x197458u;
            goto label_197458;
        }
    }
    ctx->pc = 0x1973D0u;
    // 0x1973d0: 0x24036000  addiu       $v1, $zero, 0x6000
    ctx->pc = 0x1973d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24576));
    // 0x1973d4: 0x1083001e  beq         $a0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1973D4u;
    {
        const bool branch_taken_0x1973d4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973d4) {
            ctx->pc = 0x197450u;
            goto label_197450;
        }
    }
    ctx->pc = 0x1973DCu;
    // 0x1973dc: 0x24035000  addiu       $v1, $zero, 0x5000
    ctx->pc = 0x1973dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20480));
    // 0x1973e0: 0x10830019  beq         $a0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1973E0u;
    {
        const bool branch_taken_0x1973e0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973e0) {
            ctx->pc = 0x197448u;
            goto label_197448;
        }
    }
    ctx->pc = 0x1973E8u;
    // 0x1973e8: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x1973e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x1973ec: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1973ECu;
    {
        const bool branch_taken_0x1973ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973ec) {
            ctx->pc = 0x197440u;
            goto label_197440;
        }
    }
    ctx->pc = 0x1973F4u;
    // 0x1973f4: 0x24033000  addiu       $v1, $zero, 0x3000
    ctx->pc = 0x1973f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12288));
    // 0x1973f8: 0x1083000f  beq         $a0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1973F8u;
    {
        const bool branch_taken_0x1973f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973f8) {
            ctx->pc = 0x197438u;
            goto label_197438;
        }
    }
    ctx->pc = 0x197400u;
    // 0x197400: 0x24032000  addiu       $v1, $zero, 0x2000
    ctx->pc = 0x197400u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x197404: 0x1083000a  beq         $a0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x197404u;
    {
        const bool branch_taken_0x197404 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197404) {
            ctx->pc = 0x197430u;
            goto label_197430;
        }
    }
    ctx->pc = 0x19740Cu;
    // 0x19740c: 0x24031000  addiu       $v1, $zero, 0x1000
    ctx->pc = 0x19740cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x197410: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x197410u;
    {
        const bool branch_taken_0x197410 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197410) {
            ctx->pc = 0x197428u;
            goto label_197428;
        }
    }
    ctx->pc = 0x197418u;
    // 0x197418: 0x10800010  beqz        $a0, . + 4 + (0x10 << 2)
    ctx->pc = 0x197418u;
    {
        const bool branch_taken_0x197418 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x197418) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197420u;
    // 0x197420: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x197420u;
    {
        const bool branch_taken_0x197420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197420) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197428u;
label_197428:
    // 0x197428: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x197428u;
    {
        const bool branch_taken_0x197428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19742Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197428u;
            // 0x19742c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197428) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197430u;
label_197430:
    // 0x197430: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x197430u;
    {
        const bool branch_taken_0x197430 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197430u;
            // 0x197434: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197430) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197438u;
label_197438:
    // 0x197438: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x197438u;
    {
        const bool branch_taken_0x197438 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19743Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197438u;
            // 0x19743c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197438) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197440u;
label_197440:
    // 0x197440: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x197440u;
    {
        const bool branch_taken_0x197440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197440u;
            // 0x197444: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197440) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197448u;
label_197448:
    // 0x197448: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x197448u;
    {
        const bool branch_taken_0x197448 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19744Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197448u;
            // 0x19744c: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197448) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197450u;
label_197450:
    // 0x197450: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x197450u;
    {
        const bool branch_taken_0x197450 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197450u;
            // 0x197454: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197450) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197458u;
label_197458:
    // 0x197458: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x197458u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
label_19745c:
    // 0x19745c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19745cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_197460:
    // 0x197460: 0x3e00008  jr          $ra
    ctx->pc = 0x197460u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x197464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197460u;
            // 0x197464: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1970FCu: goto label_1970fc;
            case 0x19710Cu: goto label_19710c;
            case 0x19711Cu: goto label_19711c;
            case 0x197138u: goto label_197138;
            case 0x197158u: goto label_197158;
            case 0x197168u: goto label_197168;
            case 0x197174u: goto label_197174;
            case 0x197180u: goto label_197180;
            case 0x1971A8u: goto label_1971a8;
            case 0x1971B0u: goto label_1971b0;
            case 0x1971B8u: goto label_1971b8;
            case 0x1971D8u: goto label_1971d8;
            case 0x1971E8u: goto label_1971e8;
            case 0x1971ECu: goto label_1971ec;
            case 0x197210u: goto label_197210;
            case 0x197224u: goto label_197224;
            case 0x197230u: goto label_197230;
            case 0x1972A0u: goto label_1972a0;
            case 0x1972A8u: goto label_1972a8;
            case 0x1972B0u: goto label_1972b0;
            case 0x1972B8u: goto label_1972b8;
            case 0x1972C0u: goto label_1972c0;
            case 0x1972C8u: goto label_1972c8;
            case 0x1972D0u: goto label_1972d0;
            case 0x1972D8u: goto label_1972d8;
            case 0x1972E4u: goto label_1972e4;
            case 0x197304u: goto label_197304;
            case 0x197324u: goto label_197324;
            case 0x197338u: goto label_197338;
            case 0x19734Cu: goto label_19734c;
            case 0x19736Cu: goto label_19736c;
            case 0x197378u: goto label_197378;
            case 0x197384u: goto label_197384;
            case 0x197398u: goto label_197398;
            case 0x1973B8u: goto label_1973b8;
            case 0x197428u: goto label_197428;
            case 0x197430u: goto label_197430;
            case 0x197438u: goto label_197438;
            case 0x197440u: goto label_197440;
            case 0x197448u: goto label_197448;
            case 0x197450u: goto label_197450;
            case 0x197458u: goto label_197458;
            case 0x19745Cu: goto label_19745c;
            case 0x197460u: goto label_197460;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197468u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
